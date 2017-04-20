/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nterol <nterol@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 15:20:48 by nterol            #+#    #+#             */
/*   Updated: 2017/04/20 20:31:51 by nterol           ###   ########.fr       */
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
  if (uni->love.red || uni->love.green || uni->love.blue || uni->love.der ||\
    uni->love.neerg || uni->love.eulb)
  {
    uni->a += (uni->love.blue * 1) - (uni->love.eulb * 1);
    uni->b += (uni->love.green * 1) - (uni->love.neerg * 1);
    uni->c += (uni->love.red * 1) - (uni->love.der * 1);
  }
  clear_window(uni);
  return (0);
}

int     key_press(int keycode, t_ctol *uni)
{
  keycode == ESC ? exit(42) : 0;
  keycode == PLUS ? uni->love.plus = 1 : 0;
  keycode == MINUS ? uni->love.minus = 1 : 0;
  keycode == UP ? uni->love.up = 1 : 0;
  keycode == DOWN ? uni->love.down = 1 : 0;
  if (keycode == PAUSE)
    uni->love.pause = (uni->love.pause ? 0 : 1);
  keycode == R_TOUCH ? uni->love.red = 1 : 0;
  keycode == E_TOUCH ? uni->love.der = 1 : 0;
  keycode == G_TOUCH ? uni->love.green = 1 : 0;
  keycode == F_TOUCH ? uni->love.neerg = 1 : 0;
  keycode == B_TOUCH ? uni->love.blue = 1 : 0;
  keycode == V_TOUCH ? uni->love.eulb = 1 : 0;
  return (0);
}

int     key_release(int keycode, t_ctol *uni)
{
  keycode == PLUS ? uni->love.plus = 0 : 0;
  keycode == MINUS ? uni->love.minus = 0 : 0;
  keycode == UP ? uni->love.up = 0 : 0;
  keycode == DOWN ? uni->love.down =  0 : 0;
  keycode == R_TOUCH ? uni->love.red = 0 : 0;
  keycode ==  E_TOUCH ? uni->love.der =  0 : 0;
  keycode == G_TOUCH ? uni->love.green = 0 : 0;
  keycode == F_TOUCH ? uni->love.neerg = 0 : 0;
  keycode == B_TOUCH ? uni->love.blue = 0 : 0;
  keycode == V_TOUCH ? uni->love.eulb = 0 : 0;
  return (0);
}
