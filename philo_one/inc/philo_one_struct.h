/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one_struct.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhan <yuhan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 18:20:42 by yuhan             #+#    #+#             */
/*   Updated: 2021/02/05 22:47:29 by yuhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_STRUCT_H
# define PHILO_ONE_STRUCT_H

# define FALSE		0
# define TRUE		1

# define GET_FORK	" has taken a fork\n"
# define EATING		" is eating\n"
# define SLEEPING	" is sleeping\n"
# define THINKING	" is thinking\n"
# define DIED		" has died\n"

struct				s_common;
typedef struct 		timeval
					t_timeval;

typedef struct 		s_philo
{
	struct s_common	*c;
	int				index;
	u_int32_t		count;
}					t_philo;

typedef struct		s_common
{
	int				total_number;
	u_int32_t		ttd;
	u_int32_t		tte;
	u_int32_t		tts;
	u_int32_t		must_eat;
	void			**status;
	pthread_t		*threads;
	pthread_mutex_t	*fork;
	pthread_mutex_t	fd_stdout;
	pthread_mutex_t	death;
	u_int32_t		start;
}					t_common;

#endif
