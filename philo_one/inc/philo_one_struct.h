/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one_struct.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhan <yuhan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 18:20:42 by yuhan             #+#    #+#             */
/*   Updated: 2021/02/04 19:48:38 by yuhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_STRUCT_H
# define PHILO_ONE_STRUCT_H

# define FALSE	0
# define TRUE	1

struct				s_arg;
typedef struct 		timeval
					t_timeval;

typedef struct 		s_philo
{
	struct s_arg	*a;
	int				index;
}					t_philo;

typedef struct		s_arg
{
	int				total_number;
	u_int32_t		ttd;
	u_int32_t		tte;
	u_int32_t		tts;
	u_int32_t		must_eat;
	t_philo			*philo;
	void			**status;
	pthread_t		*threads;
	pthread_mutex_t	*fork;
	pthread_mutex_t	fd_stdout;
	// int				quit;
}					t_arg;

#endif
