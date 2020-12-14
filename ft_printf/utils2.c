/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkim <hyunkim@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 02:03:41 by hyunkim           #+#    #+#             */
/*   Updated: 2020/12/10 02:03:41 by hyunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putdeci(long long data)
{
	if (data < 0)
	{
		if (-(data / 10) != 0)
			ft_putdeci(-(data / 10));
		write(1, &"0123456789"[-(data % 10)], 1);
	}
	else if (data >= 10)
	{
		ft_putdeci(data / 10);
		write(1, &"0123456789"[data % 10], 1);
	}
	else
		write(1, &"0123456789"[data % 10], 1);
}

void	ft_puthex(unsigned long long n)
{
	if (n >= 16)
	{
		ft_puthex(n / 16);
		write(1, &"0123456789ABCDEF"[n % 16], 1);
	}
	else
		write(1, &"0123456789ABCDEF"[n % 16], 1);
}

void	ft_puthex2(unsigned long long n)
{
	if (n >= 16)
	{
		ft_puthex2(n / 16);
		write(1, &"0123456789abcdef"[n % 16], 1);
	}
	else
		write(1, &"0123456789abcdef"[n % 16], 1);
}

void	ft_put_data(long long data, const char *form)
{
	if (*form == 'd' || *form == 'i' || *form == 'u')
		ft_putdeci(data);
	else if (*form == 'X')
		ft_puthex(data);
	else if (*form == 'x')
		ft_puthex2(data);
}
