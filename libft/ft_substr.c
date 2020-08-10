/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkim <hyunkim@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 04:05:34 by hyunkim           #+#    #+#             */
/*   Updated: 2020/08/05 03:57:49 by hyunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	s_len;
	size_t	index;

	index = 0;
	if (s == NULL)
		return (NULL);
	res = (char*)malloc(sizeof(char) * (len + 1));
	if (res == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	while (index + start < s_len)
	{
		if (index >= len)
			break ;
		res[index] = s[index + start];
		index++;
	}
	res[index] = '\0';
	return (res);
}
