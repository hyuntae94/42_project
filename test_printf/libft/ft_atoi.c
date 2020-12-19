/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkim <hyunkim@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 19:32:07 by hyunkim           #+#    #+#             */
/*   Updated: 2020/07/31 18:05:06 by hyunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_space(int ch)
{
	if (ch >= 9 && ch <= 13)
		return (1);
	if (ch == 32)
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int index;
	int minus;
	int res;

	index = 0;
	minus = 1;
	res = 0;
	while (is_space(str[index]) == 1)
		index++;
	if (str[index] == '+' || str[index] == '-')
	{
		if (str[index] == '-')
			minus *= -1;
		index++;
	}
	while (str[index] >= '0' && str[index] <= '9')
	{
		res *= 10;
		res += str[index] - '0';
		index++;
	}
	return (res * minus);
}
