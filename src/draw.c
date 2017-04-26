/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nterol <nterol@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 15:20:01 by nterol            #+#    #+#             */
/*   Updated: 2017/04/26 15:45:50 by nterol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void		pixel_put(int x, int y, t_ctol *uni, t_color color)
{
	t_color	*img;

	img = (t_color *)uni->env.data;
	if (x >= 0 && x < uni->w && y >= 0 && y < uni->h)
		img[y * uni->w + x] = color;
}

t_color		palette(t_ctol *uni, int e)
{
	t_color color;
	double	mu;

	mu = smooth_shading(uni, e);
	(!uni->love.o && !uni->love.p) ? set_gradient(uni, &color, mu) : 0;
	(uni->love.o && !uni->love.p) ? sin_gradient(mu, &color) : 0;
	(uni->love.p && !uni->love.o) ? cos_gradient(mu, &color) : 0;
	(uni->love.o && uni->love.p) ? another_gradient(uni, &color, mu) : 0;
	return (color);
}

double		smooth_shading(t_ctol *uni, int e)
{
	uni->env.set == 1 ? reduce_error_julia(uni, e) : 0;
	uni->env.set == 2 ? reduce_error_mandelbrot(uni, e) : 0;
	uni->env.set == 3 ? reduce_error_burningship(uni, e) : 0;
	return (mu_mu(uni));
}
