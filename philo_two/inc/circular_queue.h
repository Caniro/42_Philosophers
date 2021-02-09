/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circular_queue.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhan <yuhan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 20:02:50 by yuhan             #+#    #+#             */
/*   Updated: 2021/02/08 20:09:08 by yuhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CIRCULAR_QUEUE_H
# define CIRCULAR_QUEUE_H

typedef struct	s_cqueue
{
	int			front;
	int			rear;
	int			total;
	int			*q;
}				t_cqueue;

#endif
