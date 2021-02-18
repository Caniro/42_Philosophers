/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhan <yuhan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 21:47:02 by yuhan             #+#    #+#             */
/*   Updated: 2021/02/18 22:21:48 by yuhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void		*rest_in_peace(t_philo *p)
{
	print_timestamp(get_time_ms() - p->c->start_time, p, DIED);
	p->c->someone_died = TRUE;
	sem_wait(p->c->fd_stdout);
	sem_post(p->c->end);
	return (NULL);
}

void		wait_forks(t_philo *p)
{
	sem_wait(p->c->fork);
	print_timestamp(get_time_ms() - p->c->start_time, p, GET_FORK);
	sem_wait(p->c->fork);
	print_timestamp(get_time_ms() - p->c->start_time, p, GET_FORK);
}

void		lets_eat(t_philo *p)
{
	p->last_eat = get_time_ms();
	print_timestamp(get_time_ms() - p->c->start_time, p, EATING);
	accurate_sleep(p->c->tte);
	sem_post(p->c->fork);
	sem_post(p->c->fork);
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
