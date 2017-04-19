/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nterol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 17:54:12 by nterol            #+#    #+#             */
/*   Updated: 2016/11/28 18:01:17 by nterol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstprint(t_list *lst)
{
	while (lst != NULL)
	{
		ft_putstr("lst->content = ");
		ft_putendl((char *)lst->content);
		lst = lst->next;
	}
}
