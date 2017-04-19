/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nterol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 18:20:28 by nterol            #+#    #+#             */
/*   Updated: 2016/11/18 15:12:09 by nterol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int n)
{
	char *c;
	char *r;

	c = (char *)str;
	r = NULL;
	while (*c)
	{
		if (*c == (char)n)
			r = c;
		c++;
	}
	if (*c == (char)n)
		return ((char *)c);
	else
		return ((char *)r);
}
