/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhan <yuhan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 19:29:23 by yuhan             #+#    #+#             */
/*   Updated: 2021/02/05 21:36:37 by yuhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <pthread.h>
#include <stdio.h>

void		*func_thread1(void *name)
{
	printf("I'm %s\n", name);
	sleep(3);
	return (NULL);
}

void		*func_thread2(void *name)
{
	printf("I'm %s\n", name);
	sleep(2);
	return (NULL);
}

void		*func_thread3(void *name)
{
	printf("I'm %s\n", name);
	sleep(1);
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

	for (int i = 0; i < 3; ++i)
	{
		if (pthread_create(&threads[0], NULL, func_thread1, t1))
			error_msg("Fail to create thread 1\n.");
		if (pthread_create(&threads[1], NULL, func_thread2, t2))
			error_msg("Fail to create thread 2\n.");
		if (pthread_create(&threads[2], NULL, func_thread3, t3))
			error_msg("Fail to create thread 3\n.");
		if (pthread_join(threads[0], &status[0]))
			error_msg("Fail to create join 1\n.");
		printf("This message is printed after thread1 join.\n");
		if (pthread_join(threads[1], &status[1]))
			error_msg("Fail to create join 2\n.");
		printf("This message is printed after thread2 join.\n");
		if (pthread_join(threads[2], &status[2]))
			error_msg("Fail to create join 3\n.");
		printf("This message is printed after thread3 join.\n");
		printf("This message is printed after all threads join.\n");
	}
	printf("Thus, pthread_join function waits until its thread ends.\n");
}
