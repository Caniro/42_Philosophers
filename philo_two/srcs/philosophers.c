/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhan <yuhan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 18:19:55 by yuhan             #+#    #+#             */
/*   Updated: 2021/02/18 22:23:38 by yuhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

static void	wait_for_end(t_common *c)
{
	sem_wait(c->end);
	usleep(1000);
}

static int	is_philo_full(t_philo *p)
{
	if (p->c->must_eat > 0 && p->eating_count >= p->c->must_eat)
	{
		p->is_full = TRUE;
		return (TRUE);
	}
	return (FALSE);
}

static void	*enter_room(void *value)
{
	t_philo			*p;

	p = (t_philo *)value;
	p->last_eat = get_time_ms();
	if (create_hunger_checker(p))
		return (NULL);
	while (p->c->someone_died == FALSE)
	{
		sem_wait(p->c->room);
		wait_forks(p);
		lets_eat(p);
		sem_post(p->c->room);
		if (is_philo_full(p) || p->c->someone_died)
			break ;
		lets_sleep(p);
		lets_think(p);
	}
	return (EXIT_SUCCESS);
}

static int	create_philosophers(t_philo *p)
{
	int		i;

	i = -1;
	while (++i < p->c->total_number)
	{
		p[i].index = i;
		if (pthread_create(&p[i].thread, NULL, enter_room, &p[i]))
			return (error_msg("Error: Fail to create philosopher thread\n"));
		pthread_detach(p[i].thread);
	}
	return (EXIT_SUCCESS);
}

int			philosophers(int argc, char *argv[])
{
	t_common	c;
	t_philo		*p;

	if (init_struct(&c, &p, argc, argv))
		return (EXIT_FAILURE);
	if (c.must_eat && create_full_checker(p))
		return (EXIT_FAILURE);
	if (create_philosophers(p))
		return (EXIT_FAILURE);
	wait_for_end(&c);
	if (c.full_everyone)
		printf(ANSI_COLOR_GREEN "\nComplete!\n" ANSI_COLOR_RESET);
	else if (c.someone_died)
		printf(ANSI_COLOR_RED "\nOne Philosopher Died...\n" ANSI_COLOR_RESET);
	cleanup_philo(&p);
	return (EXIT_SUCCESS);
}
