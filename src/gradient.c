/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradient.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nterol <nterol@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 14:51:28 by nterol            #+#    #+#             */
/*   Updated: 2017/04/26 15:54:35 by nterol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void		get_gradient(double mu, t_color *color, t_ctol *uni)
{
	int		c[2];
	double	t[2];

	c[0] = (int)mu;
	t[1] = mu - c[0];
	t[0] = 1 - t[1];
	c[0] = c[0] % 8;
	c[1] = (c[0] + 1) % 8;
	color->r = uni->pablo[c[0]].r * t[0] + uni->pablo[c[1]].r * t[1];
	color->b = uni->pablo[c[0]].b * t[0] + uni->pablo[c[1]].b * t[1];
	color->g = uni->pablo[c[0]].g * t[0] + uni->pablo[c[1]].g * t[1];
}

void		set_gradient(t_ctol *uni, t_color *color, double mu)
{
	uni->pablo[0] = (t_color){15, 30, 66, 0};
	uni->pablo[1] = (t_color){47, 1, 9, 0};
	uni->pablo[2] = (t_color){100, 7, 0, 0};
	uni->pablo[3] = (t_color){177, 82, 24, 0};
	uni->pablo[4] = (t_color){229, 181, 134, 0};
	uni->pablo[5] = (t_color){191, 233, 241, 0};
	uni->pablo[6] = (t_color){0, 170, 255, 0};
	uni->pablo[7] = (t_color){0, 87, 153, 0};
	get_gradient(mu, color, uni);
}

void		another_gradient(t_ctol *uni, t_color *color, double mu)
{
	uni->pablo[0] = (t_color){209, 12, 15, 0};
	uni->pablo[1] = (t_color){120, 43, 44, 0};
	uni->pablo[2] = (t_color){55, 12, 209, 0};
	uni->pablo[3] = (t_color){2, 118, 226, 0};
	uni->pablo[4] = (t_color){29, 221, 247, 0};
	uni->pablo[5] = (t_color){195, 226, 226, 0};
	uni->pablo[6] = (t_color){67, 21, 43, 0};
	uni->pablo[7] = (t_color){14, 5, 58, 0};
	get_gradient(mu, color, uni);
}

void		sin_gradient(double mu, t_color *color)
{
	color->r = sin(mu + 0) * 127 + 128;
	color->b = sin(mu + 3) * 127 + 128;
	color->g = sin(mu + 1) * 127 + 128;
}

void		cos_gradient(double mu, t_color *color)
{
	color->r = cos(mu + 0) * 127 + 128;
	color->b = cos(mu + 3) * 127 + 128;
	color->g = cos(mu + 1) * 127 + 128;
}
