/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nterol <nterol@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 15:20:21 by nterol            #+#    #+#             */
/*   Updated: 2017/04/20 20:32:29 by nterol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void print_iter(t_ctol *uni)
{
  mlx_string_put(uni->env.init, uni->env.window, 4, 2, 0xFFFFDF, "iter:");
  mlx_string_put(uni->env.init, uni->env.window, 50, 2, 0xFFFFDF,\
    ft_itoa(uni->max_i));
}

void set_launcher(t_ctol *uni)
{
  int x;
  int y;

  y = 0;
  uni->W = uni->w / 2;
  uni->H = uni->h / 2;
  uni->gear = uni->max_i / 4;
  while (y < uni->w)
  {
    x = -1;
    while (++x < uni->h)
    {
      uni->env.set == 1 ? julia(x, y, uni) : 0;
      uni->env.set == 2 ? mandelbrot(x, y, uni) : 0;
      uni->env.set == 3 ? burningship(x, y, uni) : 0;
    }
    y++;
  }
  mlx_put_image_to_window(uni->env.init, uni->env.window, uni->env.image, 0, 0);
  print_iter(uni);
}

void hooks(t_ctol *uni)
{
  mlx_mouse_hook(uni->env.window, mouse_hook, uni);
  if (uni->env.set == 1)
    mlx_hook(uni->env.window, 6, 0, motion_notify, uni);
  mlx_hook(uni->env.window, 2, 0, key_press, uni);
  mlx_hook(uni->env.window, 3, 0, key_release, uni);
  mlx_loop_hook(uni->env.init, loop_hook, uni);
}

void init(t_ctol *uni)
{
  uni->env.init = mlx_init();
  uni->w = WIDTH;
  uni->h = HEIGHT;
  uni->env.image = mlx_new_image(uni->env.init, uni->w, uni->h);
  uni->env.window = mlx_new_window(uni->env.init, uni->w, uni->h,"Fractol");
  uni->env.data = mlx_get_data_addr(uni->env.image, &(uni->env.bpp),\
    &(uni->env.size_line), &(uni->env.endian));
  uni->zoom = 0.5;
  uni->pablo[0] = (t_color){100, 7, 0, 0};
  uni->pablo[1] = (t_color){203, 107, 32, 0};
  uni->pablo[2] = (t_color){255, 255, 237, 0};
  uni->pablo[3] = (t_color){0, 170, 255, 0};
  uni->pablo[4] = (t_color){0, 2, 0, 0};
  uni->moveX = 0;
  uni->moveY = 0;
  uni->max_i = 30;
  uni->love.pause = 0;
  uni->love.up = 0;
  uni->love.down = 0;
  uni->love.plus = 0;
  uni->love.minus = 0;
  uni->W = uni->w / 2.0;
  uni->H = uni->h / 2.0;
}

void launcher(t_ctol *uni)
{
  init(uni);
  uni->a = 0;
  uni->b = 0;
  uni->c = 0;
  set_launcher(uni);
  hooks(uni);
  mlx_loop(uni->env.init);
}
