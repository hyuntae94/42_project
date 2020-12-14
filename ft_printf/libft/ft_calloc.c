/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkim <hyunkim@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 04:07:15 by hyunkim           #+#    #+#             */
/*   Updated: 2020/07/31 19:32:38 by hyunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	void	*res;
	size_t	need;

	need = num * size;
	res = malloc(need);
	if (res == NULL)
		return (NULL);
	ft_memset(res, 0, need);
	return (res);
}
