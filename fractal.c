/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nterol <nterol@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 15:20:12 by nterol            #+#    #+#             */
/*   Updated: 2017/04/20 20:18:50 by nterol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void julia(int x, int y, t_ctol *uni)
{
  uni->R = 1.5 * (x - uni->W) / (0.5 * uni->zoom * uni->w) + uni->moveX;
  uni->I = (y - uni->H) / (0.5 * uni->zoom * uni->h) + uni->moveY;
  uni->i = 0;
  uni->R2 = uni->R * uni->R;
  uni->I2 = uni->I * uni->I;
  while (uni->i < uni->max_i && (uni->R2 + uni->I2 <= 4))
  {
    uni->I = 2 * uni->R * uni->I + uni->moveY;
    uni->R = uni->R2 - uni->I2 + uni->moveX;
    uni->R2 = uni->R * uni->R;
    uni->I2 = uni->I * uni->I;
    uni->i++;
  }
  palette(x, y, uni);
}

void mandelbrot(int x, int y, t_ctol *uni)
{
  uni->R = 0;
  uni->I = 0;
  uni->pR = 1.5 * (x - uni->W) / (0.5 * uni->zoom * uni->w) + uni->moveX;
  uni->pI = (y - uni->H) / (0.5 * uni->zoom * uni->h) + uni->moveY;
  uni->i = 0;
  uni->R2 = uni->R * uni->R;
  uni->I2 = uni->I * uni->I;
  while (uni->i < uni->max_i && (uni->R2 + uni->I2 <= 4))
  {
    uni->I = 2 * uni->R * uni->I + uni->pI;
    uni->R = uni->R2 - uni->I2 + uni->pR;
    uni->R2 = uni->R * uni->R;
    uni->I2 = uni->I * uni->I;
    uni->i++;
  }
  palette(x, y, uni);
}

void burningship(int x, int y, t_ctol *uni)
{
  // double  oldI;

  uni->R = 0;
  uni->I = 0;
  uni->pR = 1.5 * (x - uni->W) / (0.5 * uni->zoom * uni->w) + uni->moveX;
  uni->pI = (y - uni->H) / (0.5 * uni->zoom * uni->h) + uni->moveY;
  uni->i = 0;
  uni->R2 = uni->R * uni->R;
  uni->I2 = uni->I * uni->I;
  while (uni->i < uni->max_i && (uni->R2 + uni->I2 <= 4))
  {
    uni->I = 2 * fabs(uni->R * uni->I) + uni->pI;
    uni->R = uni->R2 - uni->I2 + uni->pR;
    uni->R2 = uni->R * uni->R;
    uni->I2 = uni->I * uni->I;
    uni->i++;
  }
  palette(x, y, uni);
}

int   clear_window(t_ctol *uni)
{
  mlx_clear_window(uni->env.init, uni->env.window);
  set_launcher(uni);
    return (0);
}
