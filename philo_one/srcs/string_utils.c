/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhan <yuhan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 18:07:03 by yuhan             #+#    #+#             */
/*   Updated: 2021/02/04 18:51:29 by yuhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

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

void		ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

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
