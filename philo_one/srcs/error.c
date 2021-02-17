/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhan <yuhan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 12:12:42 by yuhan             #+#    #+#             */
/*   Updated: 2021/02/17 22:18:59 by yuhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int			error_msg(const char *msg)
{
	printf("%s", msg);
	return (EXIT_FAILURE);
}

int			error_msg_end(const char *msg, t_philo *p)
{
	printf("%s", msg);
	pthread_mutex_unlock(&p->c->end);
	return (EXIT_FAILURE);
}
