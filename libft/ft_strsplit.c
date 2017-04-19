/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nterol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 11:32:09 by nterol            #+#    #+#             */
/*   Updated: 2016/11/30 14:35:14 by nterol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_countseg(char const *s, char c)
{
	int	i;
	int	sub;

	i = 0;
	sub = 0;
	if (!s)
		return (0);
	while (*s != '\0')
	{
		if (sub == 1 && *s == c)
			sub = 0;
		if (sub == 0 && *s != c)
		{
			sub = 1;
			i++;
		}
		s++;
	}
	return (i);
}

static int		ft_wdlen(char const *s, char c)
{
	int	len;

	len = 0;
	if (!s)
		return (0);
	while (*s != c && *s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

char			**ft_strsplit(char const *s, char c)
{
	int		nb;
	int		w;
	char	**tab;

	w = 0;
	nb = ft_countseg(s, c);
	tab = (char **)malloc(sizeof(char *) * nb + 1);
	if (tab == NULL)
		return (NULL);
	while (nb--)
	{
		while (*s != '\0' && *s == c)
			s++;
		tab[w] = ft_strsub(s, 0, ft_wdlen(s, c));
		if (tab[w] == NULL)
			return (NULL);
		s = s + ft_wdlen(s, c);
		w++;
	}
	tab[w] = NULL;
	return (tab);
}
