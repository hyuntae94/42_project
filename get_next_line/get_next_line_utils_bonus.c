/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkim <hyunkim@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 12:39:39 by hyunkim           #+#    #+#             */
/*   Updated: 2020/09/09 15:35:05 by hyunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	index;

	index = 0;
	while (s[index])
		index++;
	return (index);
}

char	*ft_strdup(const char *s)
{
	char	*res;
	int		slen;
	int		index;

	slen = ft_strlen(s);
	index = 0;
	if (!(res = (char *)malloc(sizeof(char) * (slen + 1))))
		return (0);
	while (s[index])
	{
		res[index] = s[index];
		index++;
	}
	res[index] = 0;
	return (res);
}

char	*ft_strjoin(char *remainder, char *buf)
{
	char	*str;
	int		i;
	int		j;

	if (!remainder)
		return (ft_strdup(buf));
	if (!buf)
		return (0);
	if (!(str = (char *)
	malloc(sizeof(char) * (ft_strlen(remainder) + ft_strlen(buf) + 1))))
		return (0);
	i = 0;
	while (remainder[i])
	{
		str[i] = remainder[i];
		i++;
	}
	free(remainder);
	remainder = 0;
	j = -1;
	while (buf[++j])
		str[i + j] = buf[j];
	str[i + j] = 0;
	return (str);
}
