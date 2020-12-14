/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkim <hyunkim@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 04:11:14 by hyunkim           #+#    #+#             */
/*   Updated: 2020/08/10 20:32:21 by hyunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t num)
{
	char		*dest;
	const char	*source;
	size_t		index;

	index = 0;
	dest = dst;
	source = src;
	if (dest == 0 && source == 0)
		return (NULL);
	if (dest <= source)
	{
		while (index++ < num)
			*dest++ = *source++;
	}
	else
	{
		dest += num - 1;
		source += num - 1;
		while (index++ < num)
			*dest-- = *source--;
	}
	return (dst);
}
