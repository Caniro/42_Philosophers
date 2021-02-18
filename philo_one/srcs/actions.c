/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhan <yuhan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 21:47:02 by yuhan             #+#    #+#             */
/*   Updated: 2021/02/18 17:27:04 by yuhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void		*rest_in_peace(t_philo *p)
{
	print_timestamp(get_time_ms() - p->c->start_time, p, DIED);
	p->c->someone_died = TRUE;
	pthread_mutex_lock(&p->c->fd_stdout);
	pthread_mutex_unlock(&p->c->end);
	return (NULL);
}

void		wait_forks(t_philo *p)
{
	while (p->c->cq.q[p->c->cq.front] != p->index)
	{
		usleep(50);
		if (p->c->someone_died)
			break ;
	}
	pthread_mutex_lock(&p->c->fork[p->index]);
	print_timestamp(get_time_ms() - p->c->start_time, p, GET_FORK);
	pthread_mutex_lock(&p->c->fork[(p->index + 1) % p->c->total_number]);
	print_timestamp(get_time_ms() - p->c->start_time, p, GET_FORK);
	pthread_mutex_lock(&p->c->queue_m);
	queue_pop(&p->c->cq);
	pthread_mutex_unlock(&p->c->queue_m);
}

void		lets_eat(t_philo *p)
{
	p->last_eat = get_time_ms();
	print_timestamp(p->last_eat - p->c->start_time, p, EATING);
	accurate_sleep(p->c->tte);
	pthread_mutex_unlock(&p->c->fork[p->index]);
	pthread_mutex_unlock(&p->c->fork[(p->index + 1) % p->c->total_number]);
	p->eating_count++;
}

void		lets_sleep(t_philo *p)
{
	print_timestamp(get_time_ms() - p->c->start_time, p, SLEEPING);
	accurate_sleep(p->c->tts);
}

void		lets_think(t_philo *p)
{
	print_timestamp(get_time_ms() - p->c->start_time, p, THINKING);
}
