/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scrambled_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhan <yuhan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 19:16:19 by yuhan             #+#    #+#             */
/*   Updated: 2021/02/04 19:43:47 by yuhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <limits.h>

pthread_mutex_t	fd_stdout;

void		ft_putnbr(long long n)
{
	if (n == LONG_LONG_MIN)
		write(1, "–9223372036854775808", 20);
	else
	{
		if (n < 0)
		{
			write(1, "-", 1);
			n *= -1;
		}
		if (n > 9)
			ft_putnbr(n / 10);
		write(1, &"0123456789"[n % 10], 1);
	}
}

void		*func_print(void *value)
{
	printf("%ld\n", 123123123123123123);
	fflush(stdout);
	return (NULL);
}

void		*func_print2(void *value)
{
	pthread_mutex_lock(&fd_stdout);
	ft_putnbr(123123123123123123);
	write(1, "\n", 1);
	pthread_mutex_unlock(&fd_stdout);
	return (NULL);
}

int			main(void)
{
	pthread_t		threads[3];
	int				i;

	i = -1;
	while (++i < 3)
		pthread_create(&threads[i], NULL, func_print, NULL);
	i = -1;
	while (++i < 3)
		pthread_join(threads[i], NULL);
	pthread_mutex_init(&fd_stdout, NULL);
	i = -1;
	while (++i < 3)
		pthread_create(&threads[i], NULL, func_print2, NULL);
	i = -1;
	while (++i < 3)
		pthread_join(threads[i], NULL);
}
