/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhan <yuhan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 18:19:55 by yuhan             #+#    #+#             */
/*   Updated: 2021/02/08 09:14:05 by yuhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int			is_time_to_die(t_timeval *before, t_philo *p)
{
	if ((get_time_ms() - \
		(u_int32_t)(before->tv_sec * 1000 + before->tv_usec / 1000)) >= \
		(u_int32_t)p->c->ttd)
		return (TRUE);
	return (FALSE);
}

int			is_philo_full(t_philo *p)
{
	if (p->c->must_eat == 0)
		return (FALSE);
	if (p->count >= p->c->must_eat)
		return (TRUE);
	return (FALSE);
}

void		*act_philo(void *value)
{
	t_philo			*p;
	t_timeval		before_eat;
	int				first_time;

	p = (t_philo *)value;
	first_time = TRUE;
	while (1)
	{
		wait_forks(p);
		if (!first_time && is_time_to_die(&before_eat, p))
			return (rest_in_peace(p));
		lets_eat(p, &before_eat, &first_time);
		if (is_philo_full(p))
			return (EXIT_SUCCESS);
		lets_sleep(p);
		lets_think(p);
	}
	return (EXIT_SUCCESS);
}

// static int	end_philo(t_common *c)
// {
// 	free(c->status);
// 	free(c->threads);
// 	free(c->fork);
// 	// 뮤텍스도 destroy
// 	return (EXIT_SUCCESS);
// }

int			philosophers(int argc, char *argv[])
{
	t_common	c;
	t_philo		*p;
	int			i;

	if (init_philo(&c, &p, argc, argv))
		return (EXIT_FAILURE);
	i = -1;
	while (++i < c.total_number)
	{
		p[i].index = i;
		if (pthread_create(&c.threads[i], NULL, act_philo, &p[i]))
			printf("Fail to create thread\n");
		pthread_detach(c.threads[i]);
		usleep(100);
	}
	pthread_mutex_lock(&c.death);
	pthread_mutex_unlock(&c.death);
	// i = -1;
	// while (++i < c.total_number)
	// 	if (pthread_join(c.threads[i], &c.status[i]))
	// 		printf("Fail to join thread\n");
	// end_philo(&c);
	return (EXIT_SUCCESS);
}
