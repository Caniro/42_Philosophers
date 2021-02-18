/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhan <yuhan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 22:15:19 by yuhan             #+#    #+#             */
/*   Updated: 2021/02/18 16:53:16 by yuhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void		print_timestamp(u_int32_t time, t_philo *p, char *str)
{
	pthread_mutex_lock(&p->c->fd_stdout);
	if (p->c->someone_died == FALSE)
		printf("%u\t%d %s", time, p->index + 1, str);
	pthread_mutex_unlock(&p->c->fd_stdout);
}

u_int32_t	get_time_ms(void)
{
	t_timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

u_int32_t	get_time_us(void)
{
	t_timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000000 + tv.tv_usec);
}

void		accurate_sleep(u_int32_t time_ms)
{
	u_int32_t	time_us;
	u_int32_t	target_time;

	time_us = time_ms * 1000;
	target_time = get_time_us() + time_us;
	while (get_time_us() < target_time)
		usleep(100);
}
