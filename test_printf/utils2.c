/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkim <hyunkim@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 14:36:20 by hyunkim           #+#    #+#             */
/*   Updated: 2020/12/10 02:03:41 by hyunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putdata(long long data)
{
	if (data < 0)
	{
		if (-(data / 10) != 0)
			ft_putdata(-(data / 10));
		write(1, &"0123456789"[-(data % 10)], 1);
	}
	else if (data >= 10)
	{
		ft_putdata(data / 10);
		write(1, &"0123456789"[data % 10], 1);
	}
	else
		write(1, &"0123456789"[data % 10], 1);
}

void	ft_puthex(unsigned long long data)
{
	if (data >= 16)
	{
		ft_puthex(data / 16);
		write(1, &"0123456789ABCDEF"[data % 16], 1);
	}
	else
		write(1, &"0123456789ABCDEF"[data % 16], 1);
}

void	ft_puthex2(unsigned long long data)
{
	if (data >= 16)
	{
		ft_puthex2(data / 16);
		write(1, &"0123456789abcdef"[data % 16], 1);
	}
	else
		write(1, &"0123456789abcdef"[data % 16], 1);
}

void	ft_put_data(long long data, const char *form)
{
	if (*form == 'd' || *form == 'i' || *form == 'u')
		ft_putdata(data);
	else if (*form == 'X')
		ft_puthex(data);
	else if (*form == 'x')
		ft_puthex2(data);
}
