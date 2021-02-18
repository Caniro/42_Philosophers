/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhan <yuhan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 12:24:22 by yuhan             #+#    #+#             */
/*   Updated: 2021/02/18 23:32:42 by yuhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

static void	*full_checker(void *value)
{
	t_philo		*p;
	int			i;

	p = (t_philo *)value;
	i = -1;
	while ((p->c->someone_died == FALSE) && (++i < p->c->total_number))
		sem_wait(p->c->full);
	if (p->c->someone_died)
		return (NULL);
	p->c->full_everyone = TRUE;
	sem_post(p->c->end);
	sem_wait(p->c->fd_stdout);
	return (NULL);
}

int			create_full_checker(t_philo *p)
{
	pthread_t	thread;

	if (pthread_create(&thread, NULL, full_checker, p))
		return (error_msg_end("Fail to create full checker thread\n", p));
	pthread_detach(thread);
	return (EXIT_SUCCESS);
}
