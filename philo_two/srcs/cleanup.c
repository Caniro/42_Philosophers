/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhan <yuhan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 12:29:38 by yuhan             #+#    #+#             */
/*   Updated: 2021/02/10 01:15:01 by yuhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void		unlink_semaphores()
{
	sem_unlink(SEM_STDOUT);
	sem_unlink(SEM_DEATH);
	sem_unlink(SEM_DEATHC);
	sem_unlink(SEM_QUEUE);
	sem_unlink(SEM_FORK);
}

int			cleanup_philo(t_philo **pp)
{
	unlink_semaphores();
	free(*pp);
	*pp = NULL;
	return (EXIT_SUCCESS);
}
