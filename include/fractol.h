/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nterol <nterol@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 15:19:53 by nterol            #+#    #+#             */
/*   Updated: 2017/04/26 15:57:49 by nterol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../lib/libft/libft.h"
# include "../lib/minilibx_macos/mlx.h"
# include <math.h>
# include <stdio.h>

# define M_UP 5
# define M_DOWN 4
# define F_TOUCH 3
# define G_TOUCH 5
# define M_RIGHT 6
# define M_LEFT 7
# define V_TOUCH 9
# define B_TOUCH 11
# define E_TOUCH 14
# define R_TOUCH 15
# define O_TOUCH 31
# define P_TOUCH 35
# define PAUSE 49
# define ESC 53
# define PLUS 69
# define MINUS 78
# define LEFT 123
# define RIGHT 124
# define UP 126
# define DOWN 125
# define WIDTH 800
# define HEIGHT 800
# define GRAND_MAX 299

typedef struct		s_key {
	int				p;
	int				o;
	int				up;
	int				down;
	int				plus;
	int				minus;
	int				next;
	int				previous;
	int				pause;

}					t_key;

typedef struct		s_color {
	unsigned char	b;
	unsigned char	g;
	unsigned char	r;
	unsigned char	a;
}					t_color;

typedef struct		s_fra {
	int				bpp;
	int				size_line;
	int				endian;
	void			*init;
	void			*window;
	void			*image;
	char			*data;
	int				set;
}					t_fra;

typedef struct		s_ctol {
	double			move_x;
	double			move_y;
	double			zoom;
	int				max_i;
	int				i;
	double			c_r;
	double			c_i;
	double			r;
	double			im;
	double			r2;
	double			i2;
	double			p_r;
	double			p_i;
	int				w;
	int				h;
	double			h_w;
	double			h_h;
	double			a;
	double			b;
	double			c;
	t_fra			env;
	t_key			love;
	t_color			pablo[8];
}					t_ctol;

int					main(int ac, char **av);
void				check_set(int ac, char **av, t_ctol *uni);
void				display(void);
void				error(void);

void				launcher(t_ctol *uni);
void				init(t_ctol *uni);
void				hooks(t_ctol *uni);
void				set_launcher(t_ctol *uni);
int					set_pause(int keycode, t_ctol *uni);

void				julia(int x, int y, t_ctol *uni);
void				mandelbrot(int x, int y, t_ctol *uni);
void				burningship(int x, int y, t_ctol *uni);
int					clear_window(t_ctol *uni);

int					mouse_hook(int keycode, int x, int y, t_ctol *uni);
int					motion_notify(int x, int y, t_ctol *uni);

int					key_press(int keycode, t_ctol *uni);
int					key_release(int keycode, t_ctol *uni);
int					loop_hook(t_ctol *uni);

void				pixel_put(int x, int y, t_ctol *uni, t_color color);
t_color				palette(t_ctol *uni, int e);
double				smooth_shading(t_ctol *uni, int e);

void				get_gradient(double mu, t_color *color, t_ctol *uni);
void				sin_gradient(double mu, t_color *color);
void				cos_gradient(double mu, t_color *color);
void				set_gradient(t_ctol *uni, t_color *color, double mu);
void				another_gradient(t_ctol *uni, t_color *color, double mu);

void				reduce_error_julia(t_ctol *uni, int e);
void				reduce_error_mandelbrot(t_ctol *uni, int e);
void				reduce_error_burningship(t_ctol *uni, int e);
double				mu_mu(t_ctol *uni);

#endif
