/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhan <yuhan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 19:29:23 by yuhan             #+#    #+#             */
/*   Updated: 2021/02/03 20:50:09 by yuhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <pthread.h>
#include <stdio.h>

void		*func_thread(void *name)
{
	printf("I'm %s\n", name);
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
}
