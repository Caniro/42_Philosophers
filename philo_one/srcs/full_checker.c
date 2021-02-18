/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhan <yuhan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 12:24:22 by yuhan             #+#    #+#             */
/*   Updated: 2021/02/18 22:54:44 by yuhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

static void	*full_checker(void *value)
{
	t_philo		*p;
	int			i;

	p = (t_philo *)value;
	while (p->c->someone_died == FALSE)
	{
		usleep(500);
		i = -1;
		while ((p->c->someone_died == FALSE) && (++i < p->c->total_number))
		{
			if (p[i].is_full == FALSE)
				break ;
			if (i == p->c->total_number - 1)
			{
				p->c->full_everyone = TRUE;
				pthread_mutex_unlock(&p->c->end);
				return (NULL);
			}
		}
	}
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
