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
	int		fd1;
	int		fd2;

	/*fd1 = open("text.txt", O_RDONLY);
	while ((value = get_next_line(fd1,&line)) > 0)
	{
		printf("%s\n",line);
		printf("@@@ %d @@@\n", value);
	}
	printf("%s\n",line);
	printf("@@@ %d\n @@@", value);
	return (0);*/

	fd1 = open("text.txt",O_RDONLY);
	fd2 = open ("text1.txt",O_RDONLY);

	value = get_next_line(fd1,&line);
	printf("fd1 line : %s\n\n",line);
	printf("value : @@ %d @@ \n\n",value);
	free(line);

	value = get_next_line(fd2,&line);
	printf("fd2 line : %s\n\n", line);
	printf("value : @@ %d @@ \n\n",value);
	free(line);

	value = get_next_line(fd1,&line);
	printf("fd1 line : %s\n\n",line);
	printf("value : @@ %d @@ \n\n",value);
	free(line);

	value = get_next_line(fd2,&line);
	printf("fd2 line : %s\n\n",line);
	printf("value : @@ %d @@ \n\n",value);
	free(line);

	value = get_next_line(fd1,&line);
	printf("fd1 line : %s\n\n",line);
	printf("value : @@ %d @@ \n\n",value);
	free(line);

	value = get_next_line(fd2,&line);
	printf("fd2 line : %s\n\n",line);
	printf("value : @@ %d @@ \n\n",value);
	free(line);

	value = get_next_line(fd1,&line);
	printf("fd1 line : %s\n\n",line);
	printf("value : @@ %d @@ \n\n",value);
	free(line);

	value = get_next_line(fd2,&line);
	printf("fd2 line : %s\n\n",line);
	printf("value : @@ %d @@ \n\n",value);
	free(line);
}
