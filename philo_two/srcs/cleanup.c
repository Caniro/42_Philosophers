/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhan <yuhan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 12:29:38 by yuhan             #+#    #+#             */
/*   Updated: 2021/02/10 00:58:50 by yuhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void		unlink_semaphores(t_common *c)
{
	sem_close(c->fd_stdout);
	sem_close(c->death);
	sem_close(c->death_check);
	sem_close(c->fork);
	sem_unlink(SEM_STDOUT);
	sem_unlink(SEM_DEATH);
	sem_unlink(SEM_DEATHC);
	sem_unlink(SEM_QUEUE);
	sem_unlink(SEM_FORK);
}

int			cleanup_philo(t_common *c, t_philo **pp)
{
	sem_post(c->death);
	unlink_semaphores(c);
	free(*pp);
	*pp = NULL;
	return (EXIT_SUCCESS);
}
