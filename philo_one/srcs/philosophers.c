/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhan <yuhan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 18:19:55 by yuhan             #+#    #+#             */
/*   Updated: 2021/02/04 20:15:05 by yuhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void		print_timestamp(t_timeval time, int index, char *str, \
							pthread_mutex_t *fd_stdout)
{
	pthread_mutex_lock(fd_stdout);
	ft_putnbr(time.tv_sec * 1000000 + time.tv_usec);
	ft_putstr(" ");
	ft_putnbr(index);
	ft_putstr(" ");
	// enum으로 flag 세워서 분기(F_FORK, F_EAT, F_SLEEP, F_THINK, F_DIE)
	// 아니면 매크로로 문자열 설정해도 괜찮을 듯
	ft_putstr(str);
	pthread_mutex_unlock(fd_stdout);
}

void		*act_philo(void *value)
{
	t_philo			*p;
	struct timeval	after_eat;
	struct timeval	before_eat;
	int				first_time;

	p = (t_philo *)value;
	first_time = TRUE;
	while (1)
	{
		pthread_mutex_lock(&p->a->fork[p->index]);
		pthread_mutex_lock(&p->a->fork[(p->index + 1) % p->a->total_number]);
		gettimeofday(&before_eat, NULL);
		print_timestamp(before_eat, p->index, "has taken a fork\n", &p->a->fd_stdout);
		if (!first_time && (before_eat.tv_sec - after_eat.tv_sec) * 1000000 + \
			(before_eat.tv_usec - after_eat.tv_usec) >= (long)p->a->ttd * 1000)
		{
			print_timestamp(before_eat, p->index, "has died\n", &p->a->fd_stdout);
			pthread_mutex_unlock(&p->a->fork[p->index]);
			pthread_mutex_unlock(&p->a->fork[(p->index + 1) % p->a->total_number]);
			return (EXIT_SUCCESS);
		}
		gettimeofday(&before_eat, NULL);
		print_timestamp(before_eat, p->index, "is eating\n", &p->a->fd_stdout);
		first_time = FALSE;
		usleep(p->a->tte * 1000);
		pthread_mutex_unlock(&p->a->fork[p->index]);
		pthread_mutex_unlock(&p->a->fork[(p->index + 1) % p->a->total_number]);
		// 횟수 체크
		gettimeofday(&after_eat, NULL);
		print_timestamp(after_eat, p->index, "is sleeping\n", &p->a->fd_stdout);
		usleep(p->a->tts * 1000);
		gettimeofday(&after_eat, NULL);
		print_timestamp(after_eat, p->index, "is thinking\n", &p->a->fd_stdout);
	}
	return (EXIT_SUCCESS);
}

static int	end_philo(t_arg **pa)
{
	free((*pa)->status);
	free((*pa)->threads);
	free((*pa)->fork);
	free((*pa));
	// 뮤텍스도 destroy
	(*pa) = NULL;
	return (EXIT_SUCCESS);
}

int			philosophers(int argc, char *argv[])
{
	t_arg		*a;
	t_philo		*p;
	u_int32_t	i;

	if (init_philo(&a, &p, argc, argv))
		return (EXIT_FAILURE);
	i = -1;
	while (++i < (u_int32_t)a->total_number)
	{
		p[i].index = i;
		if (pthread_create(&a->threads[i], NULL, act_philo, &p[i]))
			ft_putstr("Fail to create thread\n");
	}
	i = -1;
	while (++i < (u_int32_t)a->total_number)
		if (pthread_join(a->threads[i], &a->status[i]))
			ft_putstr("Fail to join thread\n");
	end_philo(&a);
	return (EXIT_SUCCESS);
}
