/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhan <yuhan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 18:04:44 by yuhan             #+#    #+#             */
/*   Updated: 2021/02/03 18:46:50 by yuhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_H
# define PHILO_ONE_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include "philo_one_struct.h"

/*
**	ft_putstr
*/

size_t		ft_strlen(const char *str);
void		ft_putstr(char *str);
int			ft_atoi(const char *str);

/*
**	philosophers
*/

int			philosophers(int argc, char *argv[]);



# include <stdio.h>


#endif
