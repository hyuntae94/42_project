/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkim <hyunkim@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 04:10:04 by hyunkim           #+#    #+#             */
/*   Updated: 2020/08/05 03:07:09 by hyunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t num)
{
	size_t index;

	if (num == 0)
		return (0);
	index = 0;
	while (*str1 != '\0' && *str1 == *str2 && index < num - 1)
	{
		str1++;
		str2++;
		index++;
	}
	return (*str1 - *str2);
}
