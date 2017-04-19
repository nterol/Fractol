/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nterol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 16:20:31 by nterol            #+#    #+#             */
/*   Updated: 2016/11/17 17:40:54 by nterol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*ret;
	int		i;

	i = 0;
	if (!(*f) || !s)
		return (NULL);
	ret = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (ret == NULL)
		return (NULL);
	while (s[i])
	{
		ret[i] = f((char)s[i]);
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
