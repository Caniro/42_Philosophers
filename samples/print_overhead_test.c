/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_overhead_test.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhan <yuhan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 17:59:32 by yuhan             #+#    #+#             */
/*   Updated: 2021/02/20 18:27:27 by yuhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <pthread.h>
#include <stdio.h>

char		run = 1;

void		*add_num(void *number)
{
	printf("Start adding number...\n");
	while (run)
	{
		(*(int *)number)++;
		// printf("%d\n", *(int *)number);
	}
	printf("End adding number!\n");
	return (NULL);
}

void		error_msg(char *msg)
{
	printf("%s", msg);
	exit(1);
}

int			main(void)
{
	pthread_t	thread;
	int			number;

	number = 0;
	if (pthread_create(&thread, NULL, add_num, &number))
		error_msg("Fail to create thread\n.");
	pthread_detach(thread);
	usleep(1000000);
	run = 0;
	usleep(1000);
	printf("\nresult of number : %d\n", number);
}
