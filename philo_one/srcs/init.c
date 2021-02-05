/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhan <yuhan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 14:32:27 by yuhan             #+#    #+#             */
/*   Updated: 2021/02/05 22:49:42 by yuhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

static int	set_argv(t_common *c, int argc, char *argv[])
{
	c->total_number = ft_atoi(argv[1]) > 1 ? ft_atoi(argv[1]) : 5;
	c->ttd = ft_atoi(argv[2]);
	c->tte = ft_atoi(argv[3]);
	c->tts = ft_atoi(argv[4]);
	if (argc == 6)
		c->must_eat = ft_atoi(argv[5]);
	return (EXIT_SUCCESS);
}

static int	init_mutexes(t_common *c)
{
	int		i;

	i = -1;
	while (++i < c->total_number)
		pthread_mutex_init(&c->fork[i], NULL);
	pthread_mutex_init(&c->fd_stdout, NULL);
	pthread_mutex_init(&c->death, NULL);
	pthread_mutex_lock(&c->death);
	return (EXIT_SUCCESS);
}

static int	set_philo(t_philo *p, t_common *c)
{
	int		i;

	i = -1;
	while (++i < c->total_number)
	{
		p[i].c = c;
		p[i].count = 0;
	}
	return (EXIT_SUCCESS);
}

int			init_philo(t_common *c, t_philo **pp, int argc, char *argv[])
{
	memset(c, 0, sizeof(t_common));
	if (!(*pp = malloc(sizeof(t_philo) * 5)))
		return (EXIT_FAILURE);
	set_argv(c, argc, argv);
	set_philo(*pp, c);
	if (!(c->fork = malloc(sizeof(pthread_mutex_t) * c->total_number)))
		return (EXIT_FAILURE);
	if (!(c->threads = malloc(sizeof(pthread_t) * c->total_number)))
		return (EXIT_FAILURE);
	if (!(c->status = malloc(sizeof(void *) * c->total_number)))
		return (EXIT_FAILURE);
	init_mutexes(c);
	c->start = get_time_ms();
	return (EXIT_SUCCESS);
}
