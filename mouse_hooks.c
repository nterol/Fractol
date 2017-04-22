/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nterol <nterol@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 17:24:22 by nterol            #+#    #+#             */
/*   Updated: 2017/04/22 18:14:34 by nterol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_hook(int keycode, int x, int y, t_ctol *uni)
{
	if (keycode == M_UP)
	{
		uni->zoom = uni->zoom * 1.05;

		uni->move_x += (x - uni->h_w) / (uni->h_w * uni->zoom) / 8;
		uni->move_y += (y - uni->h_h) / (uni->h_h * uni->zoom) / 8;
	}
	if (keycode == M_DOWN)
	{
		uni->zoom = uni->zoom * 0.95;
		uni->move_x -= (x - uni->h_w) / (uni->h_w * uni->zoom) / 8;
		uni->move_y -= (y - uni->h_h) / (uni->h_h * uni->zoom) / 8;
	}
	else
		return (0);
	set_launcher(uni);
	return (0);
}

int		motion_notify(int x, int y, t_ctol *uni)
{
	x /= 2;
	y /= 2;
	if (uni->love.pause == 1)
		return (0);
	uni->c_r = x * 0.0033;
	uni->c_i = y * 0.0033;
	set_launcher(uni);
	return (0);
}
