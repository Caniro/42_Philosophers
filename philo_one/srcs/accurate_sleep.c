/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   accurate_sleep.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhan <yuhan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 18:46:08 by yuhan             #+#    #+#             */
/*   Updated: 2021/02/08 21:08:09 by yuhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

u_int32_t	get_time_now(void)
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
	target_time = get_time_now() + time_us;
	while (get_time_now() < target_time)
		usleep(100);
}
