/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkim <hyunkim@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 04:10:35 by hyunkim           #+#    #+#             */
/*   Updated: 2020/08/05 02:24:33 by hyunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int value)
{
	size_t	index;
	char	ch;

	index = 0;
	ch = value;
	while (index < ft_strlen(str) + 1)
	{
		if (*str == ch)
			return ((char*)str);
		str++;
		index++;
	}
	return (NULL);
}
