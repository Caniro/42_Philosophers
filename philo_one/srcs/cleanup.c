/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhan <yuhan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 12:29:38 by yuhan             #+#    #+#             */
/*   Updated: 2021/02/08 13:27:14 by yuhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int			cleanup_philo(t_common *c, t_philo **pp)
{
	int		i;

	pthread_mutex_unlock(&c->death);
	pthread_mutex_destroy(&c->fd_stdout);
	pthread_mutex_destroy(&c->death);
	pthread_mutex_destroy(&c->death_check);
	i = -1;
	while (++i < c->total_number)
		pthread_mutex_destroy(&c->fork[i]);
	free(c->fork);
	c->fork = NULL;
	free(*pp);
	*pp = NULL;
	return (EXIT_SUCCESS);
}
