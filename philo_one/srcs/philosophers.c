/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhan <yuhan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 18:19:55 by yuhan             #+#    #+#             */
/*   Updated: 2021/02/08 13:23:56 by yuhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

static int	is_philo_full(t_philo *p)
{
	if (p->c->must_eat > 0 && p->eating_count >= p->c->must_eat)
		return (TRUE);
	return (FALSE);
}

static void	*act_philo(void *value)
{
	t_philo			*p;

	p = (t_philo *)value;
	gettimeofday(&p->last_eat, NULL);
	create_hunger_checker(p);
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
	return (EXIT_SUCCESS);
}

void		create_philosophers(t_philo *p)
{
	int		i;

	i = -1;
	while (++i < p->c->total_number)
	{
		p[i].index = i;
		if (pthread_create(&p[i].thread, NULL, act_philo, &p[i]))
			printf("Fail to create philosopher thread\n");
		pthread_detach(p[i].thread);
		usleep(100);
	}
}

int			philosophers(int argc, char *argv[])
{
	t_common	c;
	t_philo		*p;

	if (init_philo(&c, &p, argc, argv))
		return (EXIT_FAILURE);
	if (c.must_eat)
		create_full_checker(p);
	create_philosophers(p);
	pthread_mutex_lock(&c.death);
	if (c.complete)
		printf(ANSI_COLOR_GREEN "\nComplete!\n" ANSI_COLOR_RESET);
	else
		printf(ANSI_COLOR_RED "\nA philosopher died...\n" ANSI_COLOR_RESET);
	cleanup_philo(&c, &p);
	return (EXIT_SUCCESS);
}
