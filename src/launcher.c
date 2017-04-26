/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nterol <nterol@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 15:20:21 by nterol            #+#    #+#             */
/*   Updated: 2017/04/26 16:32:24 by nterol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	print_iter(t_ctol *uni)
{
	mlx_string_put(uni->env.init, uni->env.window, 4, 2, 0xFFFFDF, "iter:");
	mlx_string_put(uni->env.init, uni->env.window, 55, 2, 0xFFFFDF,\
			ft_itoa(uni->max_i));
}

void	set_launcher(t_ctol *uni)
{
	int	x;
	int	y;

	y = 0;
	uni->h_w = uni->w / 2;
	uni->h_h = uni->h / 2;
	while (y < uni->w)
	{
		x = -1;
		while (++x < uni->h)
		{
			uni->env.set == 0 ? julia(x, y, uni) : 0;
			uni->env.set == 1 ? mandelbrot(x, y, uni) : 0;
			uni->env.set == 2 ? burningship(x, y, uni) : 0;
		}
		y++;
	}
	mlx_put_image_to_window(uni->env.init, uni->env.window,\
			uni->env.image, 0, 0);
	print_iter(uni);
}

void	hooks(t_ctol *uni)
{
	mlx_mouse_hook(uni->env.window, mouse_hook, uni);
	if (uni->env.set == 1)
		mlx_hook(uni->env.window, 6, 0, motion_notify, uni);
	mlx_hook(uni->env.window, 2, 0, key_press, uni);
	mlx_hook(uni->env.window, 3, 0, key_release, uni);
	mlx_loop_hook(uni->env.init, loop_hook, uni);
}

void	init(t_ctol *uni)
{
	uni->env.init = mlx_init();
	uni->w = WIDTH;
	uni->h = HEIGHT;
	uni->env.image = mlx_new_image(uni->env.init, uni->w, uni->h);
	uni->env.window = mlx_new_window(uni->env.init, uni->w, uni->h, "Fractol");
	uni->env.data = mlx_get_data_addr(uni->env.image, &(uni->env.bpp),\
			&(uni->env.size_line), &(uni->env.endian));
	uni->zoom = 0.5;
	uni->move_x = 0;
	uni->move_y = 0;
	uni->max_i = 30;
	uni->love.pause = 0;
	uni->love.up = 0;
	uni->love.down = 0;
	uni->love.plus = 0;
	uni->love.minus = 0;
	uni->love.o = 0;
	uni->love.p = 0;
	uni->h_w = uni->w / 2.0;
	uni->h_h = uni->h / 2.0;
	uni->c_r = -0.7;
	uni->c_i = 0.27015;
	set_launcher(uni);
}

void	launcher(t_ctol *uni)
{
	init(uni);
	hooks(uni);
	mlx_loop(uni->env.init);
}
