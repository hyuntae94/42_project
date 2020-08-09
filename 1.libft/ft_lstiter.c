/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkim <hyunkim@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 04:10:21 by hyunkim           #+#    #+#             */
/*   Updated: 2020/08/03 16:23:20 by hyunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*curr;

	if (lst != NULL)
	{
		curr = lst;
		while (1)
		{
			(*f)(curr->content);
			curr = curr->next;
			if (curr == NULL)
				return ;
		}
	}
}
