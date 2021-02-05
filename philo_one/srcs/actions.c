/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhan <yuhan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 21:47:02 by yuhan             #+#    #+#             */
/*   Updated: 2021/02/05 23:15:48 by yuhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void		*rest_in_peace(t_philo *p)
{
	print_timestamp(get_time_ms() - p->c->start, p, DIED);
	pthread_mutex_unlock(&p->c->fork[p->index]);
	pthread_mutex_unlock(&p->c->fork[(p->index + 1) % p->c->total_number]);
	pthread_mutex_unlock(&p->c->death);
	return (EXIT_SUCCESS);
}

void		wait_forks(t_philo *p)
{
	pthread_mutex_lock(&p->c->fork[p->index]);
	print_timestamp(get_time_ms() - p->c->start, p, GET_FORK);
	pthread_mutex_lock(&p->c->fork[(p->index + 1) % p->c->total_number]);
	print_timestamp(get_time_ms() - p->c->start, p, GET_FORK);
}

void		lets_eat(t_philo *p, t_timeval *before_eat, int *first_time)
{
	gettimeofday(before_eat, NULL);
	print_timestamp(get_time_ms() - p->c->start, p, EATING);
	*first_time = FALSE;
	accurate_sleep(p->c->tte);
	pthread_mutex_unlock(&p->c->fork[p->index]);
	pthread_mutex_unlock(&p->c->fork[(p->index + 1) % p->c->total_number]);
	p->count++;
}

void		lets_sleep(t_philo *p)
{
	print_timestamp(get_time_ms() - p->c->start, p, SLEEPING);
	accurate_sleep(p->c->tts);
}

void		lets_think(t_philo *p)
{
	print_timestamp(get_time_ms() - p->c->start, p, THINKING);
}
