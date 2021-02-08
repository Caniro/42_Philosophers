/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circular_queue.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhan <yuhan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 20:02:37 by yuhan             #+#    #+#             */
/*   Updated: 2021/02/08 20:17:34 by yuhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "circular_queue.h"

void		queue_push(t_cqueue *queue, int num)
{
	if (queue->rear >= queue->total)
		queue->rear = 0;
	queue->q[queue->rear % queue->total] = num;
	queue->rear++;
}

int			queue_pop(t_cqueue *queue)
{
	int		tmp;

	tmp = queue->q[queue->front];
	queue->front++;
	if (queue->front >= queue->total)
		queue->front = 0;
	return (tmp);
}
