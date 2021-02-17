/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one_struct.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhan <yuhan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 18:20:42 by yuhan             #+#    #+#             */
/*   Updated: 2021/02/17 21:33:45 by yuhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_STRUCT_H
# define PHILO_ONE_STRUCT_H

# include "circular_queue.h"

# define FALSE		0
# define TRUE		1

# define GET_FORK	"has taken a \x1b[33mfork\x1b[0m\n"
# define EATING		"is \x1b[32meating\x1b[0m\n"
# define SLEEPING	"is \x1b[34msleeping\x1b[0m\n"
# define THINKING	"is \x1b[35mthinking\x1b[0m\n"
# define DIED		"has \x1b[31mdied\x1b[0m\n"

typedef struct timeval	t_timeval;

typedef struct		s_common
{
	int				total_number;
	u_int32_t		ttd;
	u_int32_t		tte;
	u_int32_t		tts;
	u_int32_t		must_eat;
	u_int32_t		start_time;
	int				full_everyone;
	int				someone_died;
	pthread_mutex_t	*fork;
	pthread_mutex_t	fd_stdout;
	pthread_mutex_t	end;
	pthread_mutex_t	queue_m;
	t_cqueue		cq;
}					t_common;

typedef struct		s_philo
{
	t_common		*c;
	u_int32_t		eating_count;
	int				is_full;
	int				index;
	pthread_t		thread;
	u_int32_t		last_eat;
}					t_philo;

#endif
