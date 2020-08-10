/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkim <hyunkim@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 18:46:30 by hyunkim           #+#    #+#             */
/*   Updated: 2020/08/05 01:44:53 by hyunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int input_char, size_t num)
{
	size_t	index;
	char	*str;
	char	ch;

	str = ptr;
	ch = input_char;
	index = 0;
	while (index < num)
	{
		str[index] = ch;
		index++;
	}
	return (ptr);
}
