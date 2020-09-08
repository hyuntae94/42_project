/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkim <hyunkim@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 02:20:13 by hyunkim           #+#    #+#             */
/*   Updated: 2020/09/09 02:20:13 by hyunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int		main(void)
{
	char	*line;
	int		value;
	int		fd;

	fd = open("text.txt", O_RDONLY);
	while ((value = get_next_line(fd,&line)) > 0)
	{
		printf("%s\n",line);
		printf("%d\n", value);
	}
	printf("%s\n",line);
	printf("%d\n", value);
	return (0);
}
