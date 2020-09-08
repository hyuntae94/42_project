/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkim <hyunkim@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 00:47:03 by hyunkim           #+#    #+#             */
/*   Updated: 2020/09/09 03:00:24 by hyunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	newline_index(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static int	return_line(char **remainder, char **line, int i)
{
	char	*p_next;

	(*remainder)[i] = 0;
	*line = ft_strdup(*remainder);
	i++;
	p_next = ft_strdup(*remainder + i);
	free(*remainder);
	*remainder = p_next;
	return (1);
}

int			get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	int			read_size;
	static char	*remainder;
	int			i;

	if (!line || fd < 0 || BUFFER_SIZE <= 0 || read(fd, buf, 0) < 0)
		return (-1);
	while ((read_size = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[read_size] = 0;
		remainder = strjoin_free(remainder, buf);
		if ((i = newline_index(remainder)) != -1)
			return (return_line(&remainder, line, i));
	}
	if (remainder && (i = newline_index(remainder)) != -1)
		return (return_line(&remainder, line, i));
	if (remainder)
	{
		*line = ft_strdup(remainder);
		free(remainder);
		remainder = 0;
		return (0);
	}
	*line = ft_strdup("");
	return (0);
}
