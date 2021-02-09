/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semaphore.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhan <yuhan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 23:49:17 by yuhan             #+#    #+#             */
/*   Updated: 2021/02/10 00:17:05 by yuhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>

#define SEM_FILENAME "semaphore_test"

void		error_msg(char *msg)
{
	printf("%s", msg);
	exit(1);
}

void		*func_thread(void *value)
{
	sem_t		*sem;

	sem = (sem_t *)value;
	sem_wait(sem);
	printf("Eating...\n");
	sleep(2);
	printf("Sleeping...\n");
	sem_post(sem);
	return (NULL);
}

sem_t		*init_semaphore()
{
	sem_t	*sem;

	sem = sem_open(SEM_FILENAME, O_CREAT, 0644, 2);
	if (sem == SEM_FAILED)
		return (NULL);
	return (sem);
}

int			main()
{
	sem_t		*sem;
	pthread_t	threads[3];
	void		*status[3];

	sem = init_semaphore();
	{
		if (pthread_create(&threads[0], NULL, func_thread, sem))
			error_msg("Fail to create thread 1\n.");
		if (pthread_create(&threads[1], NULL, func_thread, sem))
			error_msg("Fail to create thread 2\n.");
		if (pthread_create(&threads[2], NULL, func_thread, sem))
			error_msg("Fail to create thread 3\n.");
		if (pthread_join(threads[0], &status[0]))
			error_msg("Fail to join thread 1\n.");
		if (pthread_join(threads[1], &status[1]))
			error_msg("Fail to join thread 2\n.");
		if (pthread_join(threads[2], &status[2]))
			error_msg("Fail to join thread 3\n.");
	}
	sem_close(sem);
	sem_unlink(SEM_FILENAME);
}
