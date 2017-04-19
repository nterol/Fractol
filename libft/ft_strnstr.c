/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nterol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 18:32:06 by nterol            #+#    #+#             */
/*   Updated: 2016/11/21 11:42:52 by nterol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char const *str, char const *to_find, size_t n)
{
	size_t		i;
	size_t		j;

	i = 0;
	if (!*to_find)
		return ((char *)str);
	while (str[i] && n >= (ft_strlen((char *)to_find)) && n--)
	{
		j = 0;
		while (str[i + j] && to_find[j] && str[i + j] == to_find[j])
		{
			j++;
			if (to_find[j] == '\0')
				return ((char *)str + i);
		}
		i++;
	}
	if (to_find[0] == '\0')
		return ((char *)str + i);
	return (NULL);
}
