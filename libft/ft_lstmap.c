/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkim <hyunkim@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 04:03:31 by hyunkim           #+#    #+#             */
/*   Updated: 2020/08/04 22:23:34 by hyunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res_head;
	t_list	*res_curr;
	t_list	*curr;

	res_head = ft_lstnew((*f)(lst->content));
	if (lst == NULL || res_head == NULL)
		return (NULL);
	res_curr = res_head;
	curr = lst;
	while (1)
	{
		curr = curr->next;
		if (curr == NULL)
			break ;
		res_curr->next = ft_lstnew((*f)(curr->content));
		if (res_curr->next == NULL)
		{
			ft_lstclear(&res_head, del);
			return (NULL);
		}
		res_curr = res_curr->next;
	}
	return (res_head);
}
