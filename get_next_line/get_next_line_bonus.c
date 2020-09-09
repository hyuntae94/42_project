/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkim <hyunkim@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 12:33:29 by hyunkim           #+#    #+#             */
/*   Updated: 2020/09/09 13:00:53 by hyunkim          ###   ########.fr       */
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
	static char	*remainder[_SC_OPEN_MAX];
	int			i;

	if (!line || fd < 0 || BUFFER_SIZE <= 0 || read(fd, buf, 0) < 0)
		return (-1);
	while ((read_size = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[read_size] = 0;
		remainder[fd] = ft_strjoin(remainder[fd], buf);
		if ((i = newline_index(remainder[fd])) != -1)
			return (return_line(&remainder[fd], line, i));
	}
	if (remainder[fd] && (i = newline_index(remainder[fd])) != -1)
		return (return_line(&remainder[fd], line, i));
	if (remainder[fd])
	{
		*line = ft_strdup(remainder[fd]);
		free(remainder[fd]);
		remainder[fd] = 0;
		return (0);
	}
	*line = ft_strdup("");
	return (0);
}
