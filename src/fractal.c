/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nterol <nterol@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 15:20:12 by nterol            #+#    #+#             */
/*   Updated: 2017/04/26 13:51:38 by nterol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	julia(int x, int y, t_ctol *uni)
{
	uni->r = 1.5 * (x - uni->h_w) / (0.5 * uni->zoom * uni->w) + uni->move_x;
	uni->im = (y - uni->h_h) / (0.5 * uni->zoom * uni->h) + uni->move_y;
	uni->i = 0;
	uni->r2 = uni->r * uni->r;
	uni->i2 = uni->im * uni->im;
	while (uni->i < uni->max_i && (uni->r2 + uni->i2 <= 4))
	{
		uni->im = 2 * uni->r * uni->im + uni->c_i;
		uni->r = uni->r2 - uni->i2 + uni->c_r;
		uni->r2 = uni->r * uni->r;
		uni->i2 = uni->im * uni->im;
		uni->i++;
	}
	pixel_put(x, y, uni, palette(uni, 3));
}

void	mandelbrot(int x, int y, t_ctol *uni)
{
	uni->r = 0;
	uni->im = 0;
	uni->p_r = 1.5 * (x - uni->h_w) / (0.5 * uni->zoom * uni->w) + uni->move_x;
	uni->p_i = (y - uni->h_h) / (0.5 * uni->zoom * uni->h) + uni->move_y;
	uni->i = 0;
	uni->r2 = uni->r * uni->r;
	uni->i2 = uni->im * uni->im;
	while (uni->i < uni->max_i && (uni->r2 + uni->i2 <= 4))
	{
		uni->im = 2 * uni->r * uni->im + uni->p_i;
		uni->r = uni->r2 - uni->i2 + uni->p_r;
		uni->r2 = uni->r * uni->r;
		uni->i2 = uni->im * uni->im;
		uni->i++;
	}
	if (uni->i != uni->max_i)
		pixel_put(x, y, uni, palette(uni, 3));
	else
		pixel_put(x, y, uni, (t_color){0, 0, 0, 0});
}

void	burningship(int x, int y, t_ctol *uni)
{
	uni->r = 0;
	uni->im = 0;
	uni->p_r = 1.5 * (x - uni->h_w) / (0.5 * uni->zoom * uni->w) + uni->move_x;
	uni->p_i = (y - uni->h_h) / (0.5 * uni->zoom * uni->h) + uni->move_y;
	uni->i = 0;
	uni->r2 = uni->r * uni->r;
	uni->i2 = uni->i * uni->i;
	while (uni->i < uni->max_i && (uni->r2 + uni->i2 <= 4))
	{
		uni->im = 2.0 * fabs(uni->r * uni->im) + uni->p_i;
		uni->r = uni->r2 - uni->i2 + uni->p_r;
		uni->r2 = uni->r * uni->r;
		uni->i2 = uni->im * uni->im;
		uni->i++;
	}
	pixel_put(x, y, uni, palette(uni, 3));
}

int		clear_window(t_ctol *uni)
{
	mlx_clear_window(uni->env.init, uni->env.window);
	if (uni->max_i > 0)
		set_launcher(uni);
	return (0);
}
