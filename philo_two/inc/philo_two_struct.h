/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_two_struct.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhan <yuhan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 18:20:42 by yuhan             #+#    #+#             */
/*   Updated: 2021/02/10 19:16:14 by yuhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_TWO_STRUCT_H
# define PHILO_TWO_STRUCT_H

# include "circular_queue.h"

# define FALSE		0
# define TRUE		1

# define GET_FORK	"has taken a " ANSI_COLOR_YELLOW "fork\n" ANSI_COLOR_RESET
# define EATING		"is " ANSI_COLOR_GREEN "eating\n" ANSI_COLOR_RESET
# define SLEEPING	"is " ANSI_COLOR_BLUE "sleeping\n" ANSI_COLOR_RESET
# define THINKING	"is " ANSI_COLOR_MAGENTA "thinking\n" ANSI_COLOR_RESET
# define DIED		"has " ANSI_COLOR_RED "died\n" ANSI_COLOR_RESET

# define SEM_FORK	"sem_philosophers"
# define SEM_STDOUT	"sem_stdout"
# define SEM_DEATH	"sem_death"
# define SEM_DEATHC	"sem_death_check"
# define SEM_QUEUE	"sem_queue"

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
	u_int32_t		must_eat;
	int				complete;
	sem_t			*fork;
	sem_t			*fd_stdout;
	sem_t			*death;
	sem_t			*death_check;
	sem_t			*queue;
	t_cqueue		cq;
}					t_common;

#endif
