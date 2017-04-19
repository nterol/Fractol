/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nterol <nterol@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 15:20:48 by nterol            #+#    #+#             */
/*   Updated: 2017/04/19 19:00:19 by nterol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int     loop_hook(t_ctol *uni)
{
  if (uni->love.up || uni->love.down || uni->love.plus || uni->love.minus)
  {
    uni->zoom *= (1.0 + (uni->love.up * 0.05) - (uni->love.down * 0.05));
    uni->max_i += (uni->love.plus * 2) - (uni->love.minus * 2);

  }
  clear_window(uni);
  return (0);
}

int     mouse_hook(int keycode, int x, int y, t_ctol *uni)
{
  if (keycode == M_UP)
  {
    uni->zoom = uni->zoom * 1.05;
    uni->moveX += (x - uni->W) / (uni->W * uni->zoom) / 8;
    uni->moveY += (y - uni->H) / (uni->H * uni->zoom) / 8;
  }
  if (keycode == M_DOWN)
  {
    uni->zoom = uni->zoom * 0.95;
    uni->moveX -= (x - uni->W) / (uni->W * uni->zoom) / 8;
    uni->moveY -= (y - uni->H) / (uni->H * uni->zoom) / 8;
  }
  else
    return(0);
  set_launcher(uni);
  return (0);
}

int     motion_notify(int x, int y, t_ctol *uni)
{
  x /= 2;
  y /= 2;
  if (uni->love.pause == 1)
    return (0);
  uni->moveX = x * 0.0033;
  uni->moveY = y * 0.0033;
  set_launcher(uni);
  return (0);
}

int     key_press(int keycode, t_ctol *uni)
{
  keycode == ESC ? exit(42) : 0;
  keycode == PLUS ? uni->love.plus = 0 : 1;
  keycode == MINUS ? uni->love.minus = 1 : 0;
  keycode == UP ? uni->love.up = 1 : 0;
  keycode == DOWN ? uni->love.down = 1 : 0;
  return (0);
}

int     key_release(int keycode, t_ctol *uni)
{
  keycode == PLUS ? uni->love.plus = 0 : 0;
  keycode == MINUS ? uni->love.minus = 0 : 0;
  keycode == UP ? uni->love.up = 0 : 0;
  keycode == DOWN ? uni->love.down =  0 : 0;
  return (0);
}
