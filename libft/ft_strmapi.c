/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nterol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 16:31:37 by nterol            #+#    #+#             */
/*   Updated: 2016/11/17 17:41:42 by nterol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*op;
	int		i;

	i = 0;
	if (!(*f) || !s)
		return (NULL);
	op = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (op == NULL)
		return (NULL);
	while (s[i])
	{
		op[i] = f((unsigned int)i, (char)s[i]);
		i++;
	}
	op[i] = '\0';
	return (op);
}
