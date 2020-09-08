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

size_t	ft_strlen(const char *str)
{
	size_t index;

	index = 0;
	while (str[index])
		index++;
	return (index);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	s1_len;
	size_t	s2_len;
	int		index;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	res = (char*)malloc((s1_len + s2_len + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	index = 0;
	while (*s1 != '\0')
		res[index++] = *s1++;
	while (*s2 != '\0')
		res[index++] = *s2++;
	res[index] = '\0';
	return (res);
}

char	*ft_strdup(const char *str)
{
	size_t	len;
	char	*res;
	size_t	index;

	index = 0;
	len = ft_strlen(str);
	res = (char*)malloc((len + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	while (index < len)
	{
		res[index] = str[index];
		index++;
	}
	res[index] = '\0';
	return (res);
}

void	*ft_memset(void *ptr, int input_char, size_t num)
{
	size_t	index;
	char	*str;
	char	ch;

	str = ptr;
	ch = input_char;
	index = 0;
	while (index < num)
	{
		str[index] = ch;
		index++;
	}
	return (ptr);
}

char	*ft_strchr(const char *str, int c)
{
	size_t i;

	i = 0;
	if (c == 0)
		return ((char *)str + ft_strlen(str));
	while (str[i])
	{
		if (str[i] == (char)c)
			return ((char *)str + i);
		i++;
	}
	return (0);
}

char	*ft_strcpy(char *s1, const char *s2)
{
	int index;

	index = 0;
	while (s2[index])
	{
		s1[index] = s2[index];
		index++;
	}
	s1[index] = '\0';
	return (s1);
}
