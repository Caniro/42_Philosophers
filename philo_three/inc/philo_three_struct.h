/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_three_struct.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhan <yuhan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 18:20:42 by yuhan             #+#    #+#             */
/*   Updated: 2021/02/18 23:46:48 by yuhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_THREE_STRUCT_H
# define PHILO_THREE_STRUCT_H

# define FALSE		0
# define TRUE		1

# define GET_FORK	"has taken a \x1b[33mfork\x1b[0m\n"
# define EATING		"is \x1b[32meating\x1b[0m\n"
# define SLEEPING	"is \x1b[34msleeping\x1b[0m\n"
# define THINKING	"is \x1b[35mthinking\x1b[0m\n"
# define DIED		"has \x1b[31mdied\x1b[0m\n"

# define SEM_FORK	"sem_fork"
# define SEM_STDOUT	"sem_stdout"
# define SEM_END	"sem_end"
# define SEM_ROOM	"sem_room"
# define SEM_FULL	"sem_full"

# define CHILD_PROC	0

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
	sem_t			*fork;
	sem_t			*fd_stdout;
	sem_t			*end;
	sem_t			*room;
	sem_t			*full;
}					t_common;

typedef struct		s_philo
{
	t_common		*c;
	u_int32_t		eating_count;
	int				is_full;
	int				index;
	pthread_t		thread;
	u_int32_t		last_eat;
	pid_t			pid;
}					t_philo;

#endif
