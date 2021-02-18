/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhan <yuhan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 14:32:27 by yuhan             #+#    #+#             */
/*   Updated: 2021/02/18 23:11:49 by yuhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

static void	wait_to_end_program(t_common *c)
{
	sem_wait(c->end);
}

static int	init_semaphores(t_common *c)
{
	cleanup_semaphores();
	if ((c->fork = sem_open(SEM_FORK, O_CREAT, 0644, c->total_number)) \
		== SEM_FAILED)
		return (error_msg("Error: Fail to set semaphores\n"));
	if ((c->fd_stdout = sem_open(SEM_STDOUT, O_CREAT, 0644, 1)) \
		== SEM_FAILED)
		return (error_msg("Error: Fail to set semaphores\n"));
	if ((c->end = sem_open(SEM_END, O_CREAT, 0644, 1)) \
		== SEM_FAILED)
		return (error_msg("Error: Fail to set semaphores\n"));
	if ((c->room = sem_open(SEM_ROOM, O_CREAT, 0644, c->total_number - 1)) \
		== SEM_FAILED)
		return (error_msg("Error: Fail to set semaphores\n"));
	wait_to_end_program(c);
	return (EXIT_SUCCESS);
}

static int	init_common(t_common *c, int argc, char *argv[])
{
	c->total_number = ft_atoi_pos(argv[1]);
	c->ttd = ft_atoi_pos(argv[2]);
	c->tte = ft_atoi_pos(argv[3]);
	c->tts = ft_atoi_pos(argv[4]);
	c->must_eat = 0;
	if (argc == 6)
		c->must_eat = ft_atoi_pos(argv[5]);
	c->start_time = get_time_ms();
	c->full_everyone = FALSE;
	c->someone_died = FALSE;
	if (init_semaphores(c))
		return (EXIT_FAILURE);
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
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
