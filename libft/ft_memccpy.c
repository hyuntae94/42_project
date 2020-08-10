/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkim <hyunkim@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 04:07:43 by hyunkim           #+#    #+#             */
/*   Updated: 2020/08/04 23:19:09 by hyunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char		*dest;
	const char	*source;
	char		ch;

	dest = dst;
	source = src;
	ch = c;
	while (n--)
	{
		*dest++ = *source;
		if (*source == ch)
			return ((void*)dest);
		source++;
	}
	return (NULL);
}
