/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhan <yuhan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 14:32:27 by yuhan             #+#    #+#             */
/*   Updated: 2021/02/04 19:44:06 by yuhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

static int	set_argv(t_arg *a, int argc, char *argv[])
{
	a->total_number = ft_atoi(argv[1]) > 1 ? ft_atoi(argv[1]) : 5;
	a->ttd = ft_atoi(argv[2]);
	a->tte = ft_atoi(argv[3]);
	a->tts = ft_atoi(argv[4]);
	if (argc == 6)
		a->must_eat = ft_atoi(argv[5]);
	return (EXIT_SUCCESS);
}

static int	init_pthreads(t_arg *a)
{
	int		i;

	i = -1;
	while (++i < a->total_number)
		pthread_mutex_init(&a->fork[i], NULL);
	pthread_mutex_init(&a->fd_stdout, NULL);
	return (EXIT_SUCCESS);
}

static int	set_philo(t_philo *p, t_arg *a)
{
	int		i;

	i = -1;
	while (++i < a->total_number)
		p[i].a = a;
	return (EXIT_SUCCESS);
}

int			init_philo(t_arg **pa, t_philo **pp, int argc, char *argv[])
{
	if (!(*pa = malloc(sizeof(t_arg))))
		return (EXIT_FAILURE);
	if (!(*pp = malloc(sizeof(t_philo) * 5)))
		return (EXIT_FAILURE);
	(*pp)->a = *pa;
	memset(*pa, 0, sizeof(t_arg));
	set_argv(*pa, argc, argv);
	set_philo(*pp, *pa);
	if (!((*pa)->fork = malloc(sizeof(pthread_mutex_t) * (*pa)->total_number)))
		return (EXIT_FAILURE);
	if (!((*pa)->threads = malloc(sizeof(pthread_t) * (*pa)->total_number)))
		return (EXIT_FAILURE);
	if (!((*pa)->status = malloc(sizeof(void *) * (*pa)->total_number)))
		return (EXIT_FAILURE);
	init_pthreads(*pa);
	return (EXIT_SUCCESS);
}

