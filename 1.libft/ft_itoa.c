/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkim <hyunkim@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 04:04:37 by hyunkim           #+#    #+#             */
/*   Updated: 2020/08/10 16:55:31 by hyunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	count_size(int n)
{
	int	res;

	if (n == 0)
		return (1);
	if (n < 0)
		res = 1;
	else
		res = 0;
	while (n != 0)
	{
		n /= 10;
		res += 1;
	}
	return (res);
}

char		*ft_itoa(int n)
{
	char			*res;
	int				size;
	long long int	k;

	size = count_size(n);
	res = (char*)malloc(sizeof(char) * (size + 1));
	if (res == NULL)
		return (NULL);
	res[size] = '\0';
	k = n;
	if (k == 0)
		res[0] = '0';
	while (k != 0)
	{
		if (k < 0)
		{
			res[0] = '-';
			k *= -1;
		}
		res[size - 1] = (k % 10) + '0';
		k /= 10;
		size--;
	}
	return (res);
}
