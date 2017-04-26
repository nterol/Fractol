/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nterol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 18:07:44 by nterol            #+#    #+#             */
/*   Updated: 2017/02/09 15:30:09 by nterol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int n)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (*str == (unsigned char)n)
			return ((char *)str);
		str++;
	}
	if ((unsigned char)n == '\0')
		return ((char *)str);
	return (NULL);
}
