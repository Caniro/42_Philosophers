/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhan <yuhan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 22:15:19 by yuhan             #+#    #+#             */
/*   Updated: 2021/02/08 09:14:22 by yuhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void		print_timestamp(u_int32_t time, t_philo *p, char *str)
{
	pthread_mutex_lock(&p->c->fd_stdout);
	printf("%u %d %s", time, p->index + 1, str);
	pthread_mutex_unlock(&p->c->fd_stdout);
}

u_int32_t	get_time_ms(void)
{
	t_timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}
