/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhan <yuhan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 14:32:27 by yuhan             #+#    #+#             */
/*   Updated: 2021/02/10 19:41:35 by yuhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

static void	set_argv(t_common *c, int argc, char *argv[])
{
	c->total_number = ft_atoi(argv[1]) > 0 ? ft_atoi(argv[1]) : 5;
	c->ttd = ft_atoi(argv[2]);
	c->tte = ft_atoi(argv[3]);
	c->tts = ft_atoi(argv[4]);
	c->must_eat = argc == 6 ? ft_atoi(argv[5]) : 0;
}

static void	init_philos(t_common *c, t_philo *p)
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

static void	wait_for_end_program(t_common *c)
{
	int		i;

	i = -1;
	while (++i < c->total_number)
		sem_wait(c->full);
	sem_wait(c->death);
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
	if ((c->full = sem_open(SEM_FULL, O_CREAT, 0644, c->total_number)) \
		== SEM_FAILED)
		return (error_msg("Fail to init semaphore\n"));
	if ((c->room = sem_open(SEM_ROOM, O_CREAT, 0644, c->total_number - 1)) \
		== SEM_FAILED)
		return (error_msg("Fail to init semaphore\n"));
	wait_for_end_program(c);
	return (EXIT_SUCCESS);
}

int			init_philo(t_common *c, t_philo **pp, int argc, char *argv[])
{
	memset(c, 0, sizeof(t_common));
	set_argv(c, argc, argv);
	if (!(*pp = malloc(sizeof(t_philo) * c->total_number)))
		return (error_msg("Fail to malloc t_philo\n"));
	init_philos(c, *pp);
	if (init_semaphores(c))
		return (EXIT_FAILURE);
	c->start_time = get_time_ms();
	c->complete = FALSE;
	return (EXIT_SUCCESS);
}
