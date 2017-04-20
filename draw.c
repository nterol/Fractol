/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nterol <nterol@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 15:20:01 by nterol            #+#    #+#             */
/*   Updated: 2017/04/20 20:32:03 by nterol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void  pixel_put(int x, int y, t_ctol *uni, t_color color)
{
  t_color *img;

  img = (t_color *)uni->env.data;
  if (x >= 0 && x < uni->w && y >= 0 && y < uni->h)
    img[y * uni->w + x] = color;
}

void  palette(int x, int y, t_ctol *uni)
{
  t_color color;
  double Ir;
  double Ib;
  double Ig;

  pick_a_color(uni);

  Ir = (double)(uni->end.r - uni->begin.r) / (double)uni->max_i;
  Ib = (double)(uni->end.b - uni->begin.b) / (double)uni->max_i;
  Ig = (double)(uni->end.g - uni->begin.g) / (double)uni->max_i;

  color.r = uni->begin.r + Ir * uni->i + uni->a;
  color.b = uni->begin.b + Ib * uni->i + uni->b;
  color.g = uni->begin.g + Ig * uni->i + uni->c;
  pixel_put(x, y, uni, color);
}

void pick_a_color(t_ctol *uni)
{
  int segment;

  segment = uni->i / uni->gear;
  uni->begin = uni->pablo[segment];
  uni->end = uni->pablo[segment + 1];
  if (uni->i == uni->max_i)
    uni->end =(t_color){28, 96, 221, 0};
}
