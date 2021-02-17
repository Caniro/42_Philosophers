/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhan <yuhan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 18:19:55 by yuhan             #+#    #+#             */
/*   Updated: 2021/02/17 22:36:09 by yuhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

static void	wait_for_end(t_common *c)
{
	pthread_mutex_lock(&c->end);
}

static int	is_philo_full(t_philo *p)
{
	if (p->c->must_eat > 0 && p->eating_count >= p->c->must_eat)
		return (TRUE);
	return (FALSE);
}

static void	*sit_down(void *value)
{
	t_philo			*p;

	p = (t_philo *)value;
	p->last_eat = get_time_ms();
	if (create_hunger_checker(p))
		return (NULL);
	while (1)
	{
		wait_forks(p);
		lets_eat(p);
		if (is_philo_full(p))
			break ;
		lets_sleep(p);
		lets_think(p);
	}
	p->is_full = TRUE;
	return (NULL);
}

static int	create_philosophers(t_philo *p)
{
	int		i;

	i = -1;
	while (++i < p->c->total_number)
	{
		p[i].index = i;
		if (pthread_create(&p[i].thread, NULL, sit_down, &p[i]))
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
	cleanup_philo(&c, &p);
	return (EXIT_SUCCESS);
}
