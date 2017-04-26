/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reduce_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nterol <nterol@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 10:16:49 by nterol            #+#    #+#             */
/*   Updated: 2017/04/26 15:55:56 by nterol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void		reduce_error_julia(t_ctol *uni, int e)
{
	int		i;

	i = -1;
	while (++i < e)
	{
		uni->im = 2 * uni->r * uni->im + uni->c_i;
		uni->r = uni->r2 - uni->i2 + uni->c_r;
		uni->r2 = uni->r * uni->r;
		uni->i2 = uni->im * uni->im;
		uni->i++;
	}
}

void		reduce_error_mandelbrot(t_ctol *uni, int e)
{
	int		i;

	i = -1;
	while (++i < e)
	{
		uni->im = 2 * uni->r * uni->im + uni->p_i;
		uni->r = uni->r2 - uni->i2 + uni->p_r;
		uni->r2 = uni->r * uni->r;
		uni->i2 = uni->im * uni->im;
		uni->i++;
	}
}

void		reduce_error_burningship(t_ctol *uni, int e)
{
	int		i;

	i = -1;
	while (++i < e)
	{
		uni->im = 2.0 * fabs(uni->r * uni->im) + uni->p_i;
		uni->r = uni->r2 - uni->i2 + uni->p_r;
		uni->r2 = uni->r * uni->r;
		uni->i2 = uni->im * uni->im;
		uni->i++;
	}
}

double		mu_mu(t_ctol *uni)
{
	double	mu;
	double	square;

	square = sqrt(uni->r2 + uni->i2);
	mu = uni->i + 1 - log(log(square)) / log(2.0);
	return (mu / 8);
}
