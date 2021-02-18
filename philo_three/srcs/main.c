/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhan <yuhan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 18:01:52 by yuhan             #+#    #+#             */
/*   Updated: 2021/02/18 23:04:00 by yuhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

int			main(int argc, char *argv[])
{
	if (argc < 5)
		printf("Error: Not enough arguments\n");
	else if (argc > 6)
		printf("Error: Too many arguments\n");
	else
		return (philosophers(argc, argv));
	return (EXIT_FAILURE);
}
