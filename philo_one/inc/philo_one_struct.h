/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one_struct.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhan <yuhan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 18:20:42 by yuhan             #+#    #+#             */
/*   Updated: 2021/02/08 20:36:30 by yuhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_STRUCT_H
# define PHILO_ONE_STRUCT_H

# include "circular_queue.h"

# define FALSE		0
# define TRUE		1

# define GET_FORK	"has taken a " ANSI_COLOR_YELLOW "fork\n" ANSI_COLOR_RESET
# define EATING		"is " ANSI_COLOR_GREEN "eating\n" ANSI_COLOR_RESET
# define SLEEPING	"is " ANSI_COLOR_BLUE "sleeping\n" ANSI_COLOR_RESET
# define THINKING	"is " ANSI_COLOR_MAGENTA "thinking\n" ANSI_COLOR_RESET
# define DIED		"has " ANSI_COLOR_RED "died\n" ANSI_COLOR_RESET

struct				s_common;
typedef struct 		timeval
					t_timeval;

typedef struct 		s_philo
{
	struct s_common	*c;
	int				index;
	int				is_full;
	u_int32_t		eating_count;
	t_timeval		last_eat;
	pthread_t		thread;
}					t_philo;

typedef struct		s_common
{
	int				total_number;
	u_int32_t		ttd;
	u_int32_t		tte;
	u_int32_t		tts;
	u_int32_t		start_time;
	int				complete;
	u_int32_t		must_eat;
	pthread_mutex_t	*fork;
	pthread_mutex_t	fd_stdout;
	pthread_mutex_t	death;
	pthread_mutex_t	death_check;
	pthread_mutex_t	queue_m;
	t_cqueue		cq;
}					t_common;

#endif
