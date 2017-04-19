/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nterol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 13:01:33 by nterol            #+#    #+#             */
/*   Updated: 2017/02/09 15:01:46 by nterol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;

	new = (void *)malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	if (!content)
	{
		new->content = NULL;
		new->content_size = 0;
		new->next = NULL;
		return (new);
	}
	else
	{
		new->content_size = content_size;
		new->content = malloc(content_size);
		if (!(new->content))
			return (NULL);
		ft_memcpy(new->content, content, content_size);
	}
	new->next = NULL;
	return (new);
}
