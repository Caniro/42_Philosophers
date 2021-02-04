/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_addnum.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhan <yuhan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 20:41:36 by yuhan             #+#    #+#             */
/*   Updated: 2021/02/04 16:00:25 by yuhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <pthread.h>
#include <stdio.h>

pthread_mutex_t	g_mutex;

void		*add_num(void *number)
{
	int		i;

	pthread_mutex_lock(&g_mutex);
	printf("Start adding number...\n");
	i = -1;
	while (++i < 10000)
		(*(int *)number)++;
	pthread_mutex_unlock(&g_mutex);
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
	pthread_t	threads[3];
	void		*status[3];
	int			number;

	pthread_mutex_init(&g_mutex, NULL);
	number = 0;
	if (pthread_create(&threads[0], NULL, add_num, &number))
		error_msg("Fail to create thread 1\n.");
	if (pthread_create(&threads[1], NULL, add_num, &number))
		error_msg("Fail to create thread 2\n.");
	if (pthread_create(&threads[2], NULL, add_num, &number))
		error_msg("Fail to create thread 3\n.");
	if (pthread_join(threads[0], &status[0]))
		error_msg("Fail to join thread 1\n.");
	if (pthread_join(threads[1], &status[1]))
		error_msg("Fail to join thread 2\n.");
	if (pthread_join(threads[2], &status[2]))
		error_msg("Fail to join thread 3\n.");
	printf("\nresult of number : %d\n", number);
	pthread_mutex_destroy(&g_mutex);
}
