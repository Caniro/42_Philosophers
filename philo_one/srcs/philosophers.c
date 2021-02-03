/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhan <yuhan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 18:19:55 by yuhan             #+#    #+#             */
/*   Updated: 2021/02/03 19:04:18 by yuhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

static int	init_philo(t_philo **pp, int argc, char *argv[])
{
	if (!(*pp = malloc(sizeof(t_philo))))
		return (EXIT_FAILURE);
	memset(*pp, 0, sizeof(t_philo));
	(*pp)->number = ft_atoi(argv[1]);
	(*pp)->ttd = ft_atoi(argv[2]);
	(*pp)->tte = ft_atoi(argv[3]);
	(*pp)->tts = ft_atoi(argv[4]);
	if (argc == 6)
		(*pp)->must_eat = ft_atoi(argv[5]);
	return (EXIT_SUCCESS);
}

int			philosophers(int argc, char *argv[])
{
	t_philo	*p;

	init_philo(&p, argc, argv);
	free(p);
	return (EXIT_SUCCESS);
}
