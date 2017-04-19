/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nterol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 18:24:20 by nterol            #+#    #+#             */
/*   Updated: 2016/11/17 17:35:10 by nterol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t			i;
	unsigned int	start;
	size_t			len;
	char			*trm;

	i = 0;
	start = 0;
	if (!s)
		return (NULL);
	len = ft_strlen(s);
	while (ft_isblank(s[start]) || s[start] == '\n')
	{
		start++;
		if (s[start] == '\0')
			i = 1;
	}
	while (i == 0 && (ft_isblank(s[len - 1]) || s[len - 1] == '\n'))
		len--;
	len -= (size_t)start;
	trm = ft_strsub(s, start, len);
	if (trm == NULL)
		return (NULL);
	return (trm);
}
