/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkim <hyunkim@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 04:11:36 by hyunkim           #+#    #+#             */
/*   Updated: 2020/08/05 03:38:25 by hyunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	const char *start;

	start = str;
	while (*str)
		str++;
	while (str != start && *str != (char)ch)
		str--;
	if (*str == (char)ch)
		return ((char *)str);
	return (NULL);
}
