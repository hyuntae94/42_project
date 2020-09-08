/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkim <hyunkim@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 00:47:03 by hyunkim           #+#    #+#             */
/*   Updated: 2020/09/08 20:39:36 by hyunkim          ###   ########.fr       */
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

static int	return_line(char **temp, char **line, int i)
{
	char	*p_next;

	(*temp)[i] = 0;
	*line = ft_strdup(*temp);
	i++;
	p_next = ft_strdup(*temp + i);
	free(*temp);
	*temp = p_next;
	return (1);
}

int			get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	int			read_size;
	static char	*temp;
	int			i;

	if (!line || fd < 0 || BUFFER_SIZE <= 0 || read(fd, buf, 0) < 0)
		return (-1);
	while ((read_size = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[read_size] = '\0';
		temp = strjoin_free(temp, buf);
		if ((i = newline_index(temp)) != -1)
			return (return_line(&temp, line, i));
	}
	if (temp && (i = newline_index(temp)) != -1)
		return (return_line(&temp, line, i));
	if (temp)
	{
		*line = ft_strdup(temp);
		free(temp);
		temp = 0;
		return (0);
	}
	*line = ft_strdup("");
	return (0);
}
