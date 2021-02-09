/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhan <yuhan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 14:32:27 by yuhan             #+#    #+#             */
/*   Updated: 2021/02/10 01:12:20 by yuhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

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

static int	init_semaphores(t_common *c)
{
	unlink_semaphores();
	if ((c->fork = sem_open(SEM_FORK, O_CREAT, 0644, c->total_number)) \
		== SEM_FAILED)
		return (error_msg("Fail to init semaphore\n"));
	if ((c->fd_stdout = sem_open(SEM_STDOUT, O_CREAT, 0644, 1)) \
		== SEM_FAILED)
		return (error_msg("Fail to init semaphore\n"));
	if ((c->death = sem_open(SEM_DEATH, O_CREAT, 0644, 1)) \
		== SEM_FAILED)
		return (error_msg("Fail to init semaphore\n"));
	if ((c->death_check = sem_open(SEM_DEATHC, O_CREAT, 0644, 1)) \
		== SEM_FAILED)
		return (error_msg("Fail to init semaphore\n"));
	if ((c->queue = sem_open(SEM_QUEUE, O_CREAT, 0644, 1)) \
		== SEM_FAILED)
		return (error_msg("Fail to init semaphore\n"));
	sem_wait(c->death);
	return (EXIT_SUCCESS);
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
	if (init_semaphores(c))
		return (EXIT_FAILURE);
	if (init_cqueue(c))
		return (error_msg("Fail to malloc queue"));
	c->start_time = get_time_ms();
	c->complete = FALSE;
	return (EXIT_SUCCESS);
}
