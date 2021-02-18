/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhan <yuhan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 12:29:38 by yuhan             #+#    #+#             */
/*   Updated: 2021/02/18 23:46:37 by yuhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void		cleanup_semaphores(void)
{
	sem_unlink(SEM_STDOUT);
	sem_unlink(SEM_END);
	sem_unlink(SEM_FORK);
	sem_unlink(SEM_ROOM);
	sem_unlink(SEM_FULL);
}

int			cleanup_philo(t_philo **pp)
{
	int		i;

	i = -1;
	while (++i < (*pp)->c->total_number)
		kill((*pp)[i].pid, SIGKILL);
	cleanup_semaphores();
	if (*pp)
		free(*pp);
	*pp = NULL;
	return (EXIT_SUCCESS);
}
