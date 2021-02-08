/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cqueue_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhan <yuhan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 20:23:36 by yuhan             #+#    #+#             */
/*   Updated: 2021/02/08 20:24:37 by yuhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

typedef struct	s_cqueue
{
	int			front;
	int			rear;
	int			total;
	int			*q;
}				t_cqueue;

void			queue_push(t_cqueue *queue, int num)
{
	if (queue->rear >= queue->total)
		queue->rear = 0;
	queue->q[queue->rear % queue->total] = num;
	queue->rear++;
}

int				queue_pop(t_cqueue *queue)
{
	int		tmp;

	tmp = queue->q[queue->front];
	queue->front++;
	if (queue->front >= queue->total)
		queue->front = 0;
	return (tmp);
}

int				main()
{
	t_cqueue	q;

	q.front = 0;
	q.rear = 0;
	q.total = 5;
	q.q = malloc(sizeof(int) * 5);
	for(int i = 0; i < 5; ++i)
		q.q[i] = 0;

	for (int i = 0; i < 5; ++i)
		printf("%d ", q.q[i]);
	printf("\n");
	printf("front : %d\trear : %d\n", q.front, q.rear);

	queue_push(&q, 1);
	queue_push(&q, 3);
	queue_push(&q, 5);
	queue_push(&q, 2);
	queue_push(&q, 4);

	for (int i = 0; i < 5; ++i)
		printf("%d ", q.q[i]);
	printf("\n");
	printf("front : %d\trear : %d\n", q.front, q.rear);
	printf("pop : %d\n", queue_pop(&q));

	queue_push(&q, 4);

	for (int i = 0; i < 5; ++i)
		printf("%d ", q.q[i]);
	printf("\n");
	printf("front : %d\trear : %d\n", q.front, q.rear);
	printf("pop : %d\n", queue_pop(&q));

	free(q.q);
}
