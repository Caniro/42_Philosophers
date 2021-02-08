/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhan <yuhan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 14:32:27 by yuhan             #+#    #+#             */
/*   Updated: 2021/02/08 20:36:47 by yuhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

static void	set_argv(t_common *c, int argc, char *argv[])
{
	c->total_number = ft_atoi(argv[1]) > 0 ? ft_atoi(argv[1]) : 5;
	c->ttd = ft_atoi(argv[2]);
	c->tte = ft_atoi(argv[3]);
	c->tts = ft_atoi(argv[4]);
	c->must_eat = argc == 6 ? ft_atoi(argv[5]) : 0;
}

static void	set_philos(t_philo *p, t_common *c)
{
	int		i;

	i = -1;
	while (++i < c->total_number)
	{
		p[i].c = c;
		p[i].eating_count = 0;
		p[i].is_full = FALSE;
	}
}

static void	init_mutexes(t_common *c)
{
	int		i;

	i = -1;
	while (++i < c->total_number)
		pthread_mutex_init(&c->fork[i], NULL);
	pthread_mutex_init(&c->fd_stdout, NULL);
	pthread_mutex_init(&c->death, NULL);
	pthread_mutex_init(&c->death_check, NULL);
	pthread_mutex_init(&c->queue_m, NULL);
	pthread_mutex_lock(&c->death);
}

static int	init_cqueue(t_common *c)
{
	int		i;

	c->cq.front = 0;
	c->cq.rear = 0;
	c->cq.total = c->total_number;
	if (!(c->cq.q = malloc(sizeof(int) * c->total_number)))
		return (EXIT_FAILURE);
	i = -1;
	while (++i < c->total_number)
		if (i % 2 == 0)
			queue_push(&c->cq, i);
	i = -1;
	while (++i < c->total_number)
		if (i % 2)
			queue_push(&c->cq, i);
	return (EXIT_SUCCESS);
}

int			init_philo(t_common *c, t_philo **pp, int argc, char *argv[])
{
	memset(c, 0, sizeof(t_common));
	set_argv(c, argc, argv);
	if (!(*pp = malloc(sizeof(t_philo) * c->total_number)))
		return (error_msg("Fail to malloc t_philo\n"));
	set_philos(*pp, c);
	if (!(c->fork = malloc(sizeof(pthread_mutex_t) * c->total_number)))
		return (error_msg("Fail to malloc fork\n"));
	init_mutexes(c);
	if (init_cqueue(c))
		return (error_msg("Fail to malloc queue"));
	c->start_time = get_time_ms();
	c->complete = FALSE;
	return (EXIT_SUCCESS);
}
