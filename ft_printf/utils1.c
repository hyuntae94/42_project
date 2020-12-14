/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkim <hyunkim@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 03:01:26 by hyunkim           #+#    #+#             */
/*   Updated: 2020/12/06 03:01:26 by hyunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_isnum(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

void		arr_init(int *size, int i)
{
	int j;

	j = 0;
	while (j < i)
	{
		size[j] = 0;
		j++;
	}
}

int			hex_leng_2(unsigned long long n, int point_zero)
{
	int i;

	i = 0;
	if (n == 0)//값이 0이고
	{
		if (point_zero)//'.'정밀도가 존재하고 그값이 0인경우만
			return (0);
		else//정밀도가 존재하지않고, 존재하더라도 값이 0이아닌 경우만
			return (1);
	}
	while (n != 0 && ++i)
		n /= 16;
	return (i);
}

void		ft_putthex2(unsigned long long n)
{
	if (n >= 16)
	{
		ft_putthex2(n / 16);
		write(1, &"0123456789abcdef"[n % 16], 1);
	}
	else
		write(1, &"0123456789abcdef"[n % 16], 1);
}

int			leng(long long n, const char *form)
{
	int i;

	if (n == 0)
		return (1);
	i = 0;
	if (*form == 'd' || *form == 'i' || *form == 'u')
		while (n != 0 && ++i)
			n /= 10;
	else if (*form == 'x' || *form == 'X')
		while (n != 0 && ++i)
			n /= 16;
	return (i);
}
