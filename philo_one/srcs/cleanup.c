/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhan <yuhan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 12:29:38 by yuhan             #+#    #+#             */
/*   Updated: 2021/02/18 17:14:37 by yuhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void		cleanup_mutex(t_common *c)
{
	int		i;

	i = -1;
	while (++i < c->total_number)
		pthread_mutex_destroy(&c->fork[i]);
	pthread_mutex_destroy(&c->fd_stdout);
	pthread_mutex_unlock(&c->end);
	pthread_mutex_destroy(&c->end);
	pthread_mutex_destroy(&c->queue_m);
}

int			cleanup_philo(t_common *c, t_philo **pp)
{
	cleanup_mutex(c);
	if (c->fork)
		free(c->fork);
	c->fork = NULL;
	if (c->cq.q)
		free(c->cq.q);
	c->cq.q = NULL;
	if (*pp)
		free(*pp);
	*pp = NULL;
	return (EXIT_SUCCESS);
}
