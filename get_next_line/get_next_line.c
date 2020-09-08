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

char	*check_remainder(char *remainder, char **line)
{
	char *p_n;

	p_n = NULL;
	if (remainder)
		if (p_n = ft_strchr(remainder, '\n'))
		{
			*p_n = '\0';
			*line = ft_strdup(remainder);
			ft_strcpy(remainder, ++p_n);
		}
		else
		{
			*line = ft_strdup(remainder);
			remainder = ft_memset(remainder, 0, ft_strlen(remainder));
		}
	else
		*line = ft_memset(*line, 0, ft_strlen(*line));
	return (p_n);
}

int		get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	int			byte_was_read;
	char		*p_n;
	static char	*remainder;
	char		*tmp;

	p_n = check_remainder(remainder, line);
	while (!p_n && (byte_was_read = read(fd, buf, BUFFER_SIZE)))
	{
		buf[byte_was_read] = '\0';
		if (p_n = ft_strchr(buf, '\n'))
		{
			*p_n = '\0';
			p_n++;
			remainder = ft_strdup(p_n);
		}
		*line = ft_strjoin(*line, buf);
	}
	return (byte_was_read || ft_strlen(remainder) || ft_strlen(*line)) ? 1 : 0;
}
