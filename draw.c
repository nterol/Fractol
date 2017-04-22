/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nterol <nterol@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 15:20:01 by nterol            #+#    #+#             */
/*   Updated: 2017/04/22 18:47:06 by nterol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		pixel_put(int x, int y, t_ctol *uni, t_color color)
{
	t_color	*img;

	img = (t_color *)uni->env.data;
	if (x >= 0 && x < uni->w && y >= 0 && y < uni->h)
		img[y * uni->w + x] = color;
}

void		palette(int x, int y, t_ctol *uni)
{
	t_color color;
	double	t1;
	double	t2;

	uni->une = (int)uni->mu % 16;
	t2 = uni->mu - uni->une;
	t1 = 1 - t2;
	uni->deux = (uni->une + 1) % 16;
	color.r = (unsigned char)(uni->pablo[uni->une].r * t1 +\
		uni->pablo[uni->deux].r * t2);
	color.b = (unsigned char)(uni->pablo[uni->une].b * t1 +\
		uni->pablo[uni->deux].b * t2);
	color.g = (unsigned char)(uni->pablo[uni->une].g * t1 +\
		uni->pablo[uni->deux].g * t2);
	pixel_put(x, y, uni, color);
}

void 		set_gradient(t_ctol *uni)
{
	uni->pablo[0] = (t_color){15, 30, 66, 0};
	uni->pablo[1] = (t_color){26, 7, 26, 0};
	uni->pablo[2] = (t_color){47, 1, 9, 0};
	uni->pablo[3] = (t_color){73, 4, 4, 0};
	uni->pablo[4] = (t_color){100, 7, 0, 0};
	uni->pablo[5] = (t_color){138, 44, 12, 0};
	uni->pablo[6] = (t_color){177, 82, 24, 0};
	uni->pablo[7] = (t_color){209, 125, 57, 0};
	uni->pablo[8] = (t_color){229, 181, 134, 0};
	uni->pablo[9] = (t_color){248, 236, 211, 0};
	uni->pablo[10] = (t_color){191, 233, 241, 0};
	uni->pablo[11] = (t_color){95, 201, 248, 0};
	uni->pablo[12] = (t_color){0, 170, 255, 0};
	uni->pablo[13] = (t_color){0, 128, 204, 0};
	uni->pablo[14] = (t_color){0, 87, 153, 0};
	uni->pablo[15] = (t_color){3, 52, 106, 0};
}
