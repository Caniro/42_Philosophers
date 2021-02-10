/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhan <yuhan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 12:24:22 by yuhan             #+#    #+#             */
/*   Updated: 2021/02/10 19:25:19 by yuhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

static void	*full_checker(void *value)
{
	t_philo		*p;
	int			i;

	p = (t_philo *)value;
	while (1)
	{
		usleep(1000);
		i = -1;
		while (++i < p->c->total_number)
		{
			if (p[i].is_full == FALSE)
				break ;
			if (i == p->c->total_number - 1)
			{
				p->c->complete = TRUE;
				sem_post(p->c->death);
				return (NULL);
			}
		}
	}
}

void		create_full_checker(t_philo *p)
{
	pthread_t	thread;

	if (pthread_create(&thread, NULL, full_checker, p))
		printf("Fail to create full checker thread\n");
	pthread_detach(thread);
}
