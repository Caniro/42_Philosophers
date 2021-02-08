/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhan <yuhan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 18:04:44 by yuhan             #+#    #+#             */
/*   Updated: 2021/02/08 09:11:15 by yuhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_H
# define PHILO_ONE_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <pthread.h>
# include <limits.h>
# include <stdio.h>
# include "philo_one_struct.h"

/*
**	accurate_sleep
*/

void		accurate_sleep(u_int32_t time_ms);

/*
**	actions
*/

void		*rest_in_peace(t_philo *p);
void		wait_forks(t_philo *p);
void		lets_eat(t_philo *p, t_timeval *a, int *first_time);
void		lets_sleep(t_philo *p);
void		lets_think(t_philo *p);

/*
**	init
*/

int			init_philo(t_common *pc, t_philo **pp, int argc, char *argv[]);

/*
**	philosophers
*/

int			philosophers(int argc, char *argv[]);

/*
**	string_utils
*/

size_t		ft_strlen(const char *str);
void		ft_putstr(char *str);
int			ft_atoi(const char *str);
void		ft_putnbr(long long n);

/*
**	time
*/

void		print_timestamp(u_int32_t time, t_philo *p, char *str);
u_int32_t	get_time_ms(void);

#endif
