/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nterol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 23:16:44 by nterol            #+#    #+#             */
/*   Updated: 2016/11/15 14:29:18 by nterol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*v;

	v = (unsigned char *)malloc(sizeof(size_t) * size);
	if (v == NULL)
		return (NULL);
	ft_bzero(v, size);
	if ((unsigned char *)v)
		return ((unsigned char *)v);
	else
		return (NULL);
}
