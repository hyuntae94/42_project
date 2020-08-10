/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkim <hyunkim@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 04:08:53 by hyunkim           #+#    #+#             */
/*   Updated: 2020/08/05 01:05:49 by hyunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *ptr, int value, size_t n)
{
	const char	*str;
	char		ch;

	str = (const char *)ptr;
	ch = value;
	while (n--)
	{
		if (*str == ch)
			return ((void*)str);
		str++;
	}
	return (NULL);
}
