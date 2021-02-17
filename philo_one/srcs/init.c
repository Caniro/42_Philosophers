/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhan <yuhan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 14:32:27 by yuhan             #+#    #+#             */
/*   Updated: 2021/02/17 21:55:40 by yuhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

static int	init_cqueue(t_common *c)
{
	int		i;

	c->cq.front = 0;
	c->cq.rear = 0;
	c->cq.total = c->total_number;
	c->cq.q = malloc(sizeof(int) * c->total_number);
	if (c->cq.q == NULL)
		return (EXIT_FAILURE);
	i = 0;
	while (i < c->total_number)
	{
		queue_push(&c->cq, i);
		i += 2;
	}
	i = 1;
	while (i < c->total_number)
	{
		queue_push(&c->cq, i);
		i += 2;
	}
	return (EXIT_SUCCESS);
}

static void	init_mutexes(t_common *c)
{
	int		i;

	i = -1;
	while (++i < c->total_number)
		pthread_mutex_init(&c->fork[i], NULL);
	pthread_mutex_init(&c->fd_stdout, NULL);
	pthread_mutex_init(&c->end, NULL);
	pthread_mutex_init(&c->queue_m, NULL);
	pthread_mutex_lock(&c->end);
}

static int	init_common(t_common *c, int argc, char *argv[])
{
	c->total_number = ft_atoi_pos(argv[1]);
	c->ttd = ft_atoi_pos(argv[2]);
	c->tte = ft_atoi_pos(argv[3]);
	c->tts = ft_atoi_pos(argv[4]);
	c->must_eat = (argc == 6) ? ft_atoi(argv[5]) : 0;
	c->start_time = get_time_ms();
	c->full_everyone = FALSE;
	c->someone_died = FALSE;
	c->fork = malloc(sizeof(pthread_mutex_t) * c->total_number);
	if (c->fork == NULL || init_cqueue(c))
		return (error_msg("Error: Fail to allocate memory\n"));
	init_mutexes(c);
	return (EXIT_SUCCESS);
}

static int	init_philos(t_philo **pp, t_common *c)
{
	t_philo	*p;
	int		i;

	*pp = malloc(sizeof(t_philo) * c->total_number);
	if (*pp == NULL)
		return (error_msg("Error: Fail to allocate memory\n"));
	p = *pp;
	i = -1;
	while (++i < c->total_number)
	{
		p[i].c = c;
		p[i].eating_count = 0;
		p[i].is_full = FALSE;
	}
	return (EXIT_SUCCESS);
}

int			init_struct(t_common *c, t_philo **pp, int argc, char *argv[])
{
	if (init_common(c, argc, argv) || init_philos(pp, c))
		return (error_msg("Error: Fail to allocate memory\n"));
	return (EXIT_SUCCESS);
}
