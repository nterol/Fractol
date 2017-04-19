/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nterol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 15:43:06 by nterol            #+#    #+#             */
/*   Updated: 2016/11/18 15:30:41 by nterol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*first;

	first = NULL;
	if (lst)
	{
		first = f(ft_lstnew(lst->content, lst->content_size));
		new = first;
		while ((lst = lst->next))
		{
			new->next = f(ft_lstnew(lst->content, lst->content_size));
			new = new->next;
		}
		return (first);
	}
	return (NULL);
}
