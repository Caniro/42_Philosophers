/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhan <yuhan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 20:41:36 by yuhan             #+#    #+#             */
/*   Updated: 2021/02/03 21:46:49 by yuhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <pthread.h>
#include <stdio.h>

pthread_mutex_t		g_number;

void		*func_thread(void *name)
{
	pthread_mutex_lock(&g_number);
	printf("%s is eating...\n", name);
	sleep(1);
	printf("%s starts thinking...\n", name);
	pthread_mutex_unlock(&g_number);
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
	char		t1[] = "thread_1";
	char		t2[] = "thread_2";
	char		t3[] = "thread_3";

	pthread_mutex_init(&g_number, NULL);
	for (int i = 0; i < 3; ++i)
	{
		if (pthread_create(&threads[0], NULL, func_thread, t1))
			error_msg("Fail to create thread 1\n.");
		if (pthread_create(&threads[1], NULL, func_thread, t2))
			error_msg("Fail to create thread 2\n.");
		if (pthread_create(&threads[2], NULL, func_thread, t3))
			error_msg("Fail to create thread 3\n.");
		if (pthread_join(threads[0], &status[0]))
			error_msg("Fail to create join 1\n.");
		if (pthread_join(threads[1], &status[1]))
			error_msg("Fail to create join 2\n.");
		if (pthread_join(threads[2], &status[2]))
			error_msg("Fail to create join 3\n.");
		printf("\n");
	}
	pthread_mutex_destroy(&g_number);
}
