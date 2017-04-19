/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nterol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 18:59:05 by nterol            #+#    #+#             */
/*   Updated: 2016/12/02 11:56:46 by nterol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	d_len;
	char	*d_cpy;
	char	*s_cpy;

	i = size;
	d_cpy = dst;
	s_cpy = (char *)src;
	while (i-- && *d_cpy)
		d_cpy++;
	d_len = d_cpy - dst;
	i = size - d_len;
	if (i == 0)
		return (d_len + ft_strlen((char *)s_cpy));
	while (*s_cpy)
	{
		if (i != 1)
		{
			*d_cpy++ = *s_cpy;
			--i;
		}
		s_cpy++;
	}
	*d_cpy = '\0';
	return (d_len + (s_cpy - src));
}
