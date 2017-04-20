/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nterol <nterol@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 17:24:22 by nterol            #+#    #+#             */
/*   Updated: 2017/04/20 17:26:04 by nterol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
