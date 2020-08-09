/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkim <hyunkim@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 04:11:27 by hyunkim           #+#    #+#             */
/*   Updated: 2020/08/05 02:25:12 by hyunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
