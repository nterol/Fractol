/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nterol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 23:46:05 by nterol            #+#    #+#             */
/*   Updated: 2016/12/05 14:01:46 by nterol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *r;

	r = (char*)malloc(sizeof(char) * size + 1);
	if (r == NULL)
		return (NULL);
	ft_memset((void *)r, 0, size + 1);
	return (r);
}
