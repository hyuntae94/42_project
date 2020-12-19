/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkim <hyunkim@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 04:05:20 by hyunkim           #+#    #+#             */
/*   Updated: 2020/08/05 02:43:56 by hyunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	size_t	dlen;
	size_t	slen;
	size_t	index1;
	size_t	index2;

	dlen = 0;
	slen = 0;
	while (dest[dlen])
		dlen++;
	while (src[slen])
		slen++;
	index1 = dlen;
	index2 = 0;
	while (src[index2] && index1 + 1 < size)
	{
		dest[index1] = src[index2];
		index1++;
		index2++;
	}
	dest[index1] = '\0';
	if (dlen >= size)
		return (slen + size);
	else
		return (slen + dlen);
}
