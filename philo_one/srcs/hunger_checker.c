/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hunger_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhan <yuhan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 12:28:27 by yuhan             #+#    #+#             */
/*   Updated: 2021/02/08 20:58:15 by yuhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

static int	is_time_to_die(t_philo *p)
{
	if ((get_time_ms() - \
		(u_int32_t)(p->last_eat.tv_sec * 1000 + p->last_eat.tv_usec / 1000)) >= \
		(u_int32_t)p->c->ttd)
		return (TRUE);
	return (FALSE);
}

static void	*hunger_checker(void *value)
{
	t_philo			*p;

	p = (t_philo *)value;
	while (1)
	{
		if (p->is_full)
			break ;
		pthread_mutex_lock(&p->c->death_check);
		if (is_time_to_die(p))
			return (rest_in_peace(p));
		pthread_mutex_unlock(&p->c->death_check);
		usleep(1000);
	}
	return (NULL);
}

void		create_hunger_checker(t_philo *p)
{
	pthread_t	thread;

	if (pthread_create(&thread, NULL, hunger_checker, p))
		printf("Fail to create hunger checker thread.\n");
	pthread_detach(thread);
}
