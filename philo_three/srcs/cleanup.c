/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhan <yuhan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 12:29:38 by yuhan             #+#    #+#             */
/*   Updated: 2021/02/10 19:39:35 by yuhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void		unlink_semaphores()
{
	sem_unlink(SEM_STDOUT);
	sem_unlink(SEM_DEATH);
	sem_unlink(SEM_DEATHC);
	sem_unlink(SEM_FORK);
	sem_unlink(SEM_FULL);
	sem_unlink(SEM_ROOM);
}

int			cleanup_philo(t_philo **pp)
{
	int		i;

	i = -1;
	while (++i < (*pp)->c->total_number)
		kill((*pp)[i].pid, SIGKILL);
	unlink_semaphores();
	free(*pp);
	*pp = NULL;
	return (EXIT_SUCCESS);
}
