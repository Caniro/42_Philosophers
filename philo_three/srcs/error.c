/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhan <yuhan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 12:12:42 by yuhan             #+#    #+#             */
/*   Updated: 2021/02/18 23:08:57 by yuhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

int			error_msg(const char *msg)
{
	printf("%s", msg);
	return (EXIT_FAILURE);
}

int			error_msg_end(const char *msg, t_philo *p)
{
	printf("%s", msg);
	sem_post(p->c->end);
	return (EXIT_FAILURE);
}
