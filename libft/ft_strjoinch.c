/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinch.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nterol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 13:36:11 by nterol            #+#    #+#             */
/*   Updated: 2017/02/16 18:57:10 by nterol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinch(const char *str, char c)
{
	char	*join;
	size_t	len;
	size_t	i;

	i = 0;
	if (!str || !c)
		return (NULL);
	len = ft_strlen(str);
	join = (ft_strnew(len) + 1);
	if (!join)
		return (NULL);
	while (i < len)
	{
		join[i] = str[i];
		i++;
	}
	join[i] = c;
	return (join);
}
