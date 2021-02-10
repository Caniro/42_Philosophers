/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhan <yuhan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 22:15:19 by yuhan             #+#    #+#             */
/*   Updated: 2021/02/10 19:16:53 by yuhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void		print_timestamp(u_int32_t time, t_philo *p, char *str)
{
	sem_wait(p->c->fd_stdout);
	printf(ANSI_COLOR_RESET);
	printf("%u\t%d %s", time, p->index + 1, str);
	sem_post(p->c->fd_stdout);
}

u_int32_t	get_time_ms(void)
{
	t_timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}
