/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hunger_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhan <yuhan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 12:28:27 by yuhan             #+#    #+#             */
/*   Updated: 2021/02/17 22:19:57 by yuhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

static int	is_time_to_die(t_philo *p)
{
	if (get_time_ms() >= (p->last_eat + p->c->ttd))
		return (TRUE);
	return (FALSE);
}

static void	*hunger_checker(void *value)
{
	t_philo			*p;

	p = (t_philo *)value;
	while (p->is_full == FALSE)
	{
		if (is_time_to_die(p))
			return (rest_in_peace(p));
		usleep(1000);
	}
	return (NULL);
}

int			create_hunger_checker(t_philo *p)
{
	pthread_t	thread;

	if (pthread_create(&thread, NULL, hunger_checker, p))
		return (error_msg_end("Error: Fail to create hunger checker\n", p));
	pthread_detach(thread);
	return (EXIT_SUCCESS);
}
