/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhan <yuhan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 18:07:03 by yuhan             #+#    #+#             */
/*   Updated: 2021/02/18 23:08:51 by yuhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

size_t		ft_strlen(const char *str)
{
	int		i;

	i = -1;
	while (str[++i])
		;
	return (i);
}

int			ft_atoi(const char *str)
{
	int		i;
	int		sign;
	int		num;

	num = 0;
	i = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	if (ft_strlen(str + i) > 19)
		return (sign == -1 ? 0 : -1);
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num * sign);
}

u_int32_t	ft_atoi_pos(const char *str)
{
	int		num;

	num = ft_atoi(str);
	if (num > 0)
		return (num);
	return (-num);
}
