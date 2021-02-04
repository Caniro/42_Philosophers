/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gettimeofday.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhan <yuhan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 18:36:30 by yuhan             #+#    #+#             */
/*   Updated: 2021/02/04 18:38:38 by yuhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/time.h>

int			main(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	printf("tv.tv_sec : %ld\t\ttv.tv_usec : %d\n", tv.tv_sec, tv.tv_usec);
	printf("timestamp_in_ms : %ld\n", tv.tv_sec * 1000000 + tv.tv_usec);
}
