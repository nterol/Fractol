/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nterol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 20:18:06 by nterol            #+#    #+#             */
/*   Updated: 2016/11/10 19:04:34 by nterol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(char *str, char *to_find)
{
	int i;
	int j;
	int nb;

	i = 0;
	j = 0;
	nb = 0;
	while (to_find[nb])
		nb++;
	if (nb == 0)
		return (str);
	while (str[i])
	{
		while (to_find[j] == str[i + j])
		{
			if (j == nb - 1)
				return (str + i);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
