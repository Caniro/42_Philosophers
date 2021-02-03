/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhan <yuhan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 18:01:52 by yuhan             #+#    #+#             */
/*   Updated: 2021/02/03 19:03:56 by yuhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int			main(int argc, char *argv[])
{
	if (argc < 5)
		ft_putstr("Not enough arguments.\n");
	else if (argc > 6)
		ft_putstr("Too much arguments.\n");
	else
		return (philosophers(argc, argv));
	return (EXIT_FAILURE);
}

/*
	인자
	1. number_of_philosophers : 철학자, 포크 수
	2. time_to_die : 이 시간동안 안먹으면 죽음(ms)
	3. time_to_eat : 먹는데 걸리는 시간(ms)
	4. time_to_sleep : 자는 시간(ms)
	5. number_of_times_each_philosopher_must_eat : 모든 철학자가 이만큼 먹으면 종료(인자 없으면 철학자가 죽을때까지 루프)
*/
