/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkim <hyunkim@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 20:22:12 by hyunkim           #+#    #+#             */
/*   Updated: 2020/09/08 20:43:11 by hyunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strdup(const char *s)
{
	char	*dup;
	int		slen;
	int		i;

	slen = ft_strlen(s);
	i = 0;
	if (!(dup = (char *)malloc(sizeof(char) * (slen + 1))))
		return (0);
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = 0;
	return (dup);
}

char	*strjoin_free(char *temp, char *buf)
{
	char	*str;
	int		i;
	int		j;

	if (!temp)
		return (ft_strdup(buf));
	if (!buf)
		return (0);
	if (!(str = (char *)malloc(sizeof(char) * (ft_strlen(temp) + ft_strlen(buf) + 1))))
		return (0);
	i = 0;
	while (temp[i])
	{
		str[i] = temp[i];
		i++;
	}
	free(temp);
	temp = 0;
	j = -1;
	while (buf[++j])
		str[i + j] = buf[j];
	str[i + j] = 0;
	return (str);
}
