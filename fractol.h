/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nterol <nterol@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 15:19:53 by nterol            #+#    #+#             */
/*   Updated: 2017/04/20 20:31:22 by nterol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include "minilibx_macos/mlx.h"
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

typedef struct  s_key {

  int           p;
  int           up;
  int           down;
  int           plus;
  int           minus;
  int           pause;
  int           red;
  int           der;
  int           green;
  int           neerg;
  int           blue;
  int           eulb;
}               t_key;

typedef struct  s_color {

  unsigned char b;
  unsigned char g;
  unsigned char r;
  unsigned char a;
}               t_color;

typedef struct s_fra {
  int           bpp;
  int           size_line;
  int           endian;
  void          *init;
  void          *window;
  void          *image;
  char          *data;
  int           set;

}             t_fra;

typedef struct s_ctol {

  double        moveX;
  double        moveY;
  double        zoom;
  int           max_i;
  int           i;
  double        cR;
  double        cI;
  double        R;
  double        I;
  double        R2;
  double        I2;
  double        pR;
  double        pI;
  int           w;
  int           h;
  double        W;
  double        H;
  int           gear;
  double        a;
  double        b;
  double        c;

  t_fra         env;
  t_key         love;
  t_color       begin;
  t_color       end;
  t_color       pablo[5];
}               t_ctol;

// main.c functions :
int             main(int ac, char **av);
void            check_set(int ac, char **av, t_ctol *uni);
void            display(void);
void            error(void);

// launcher.c functions :
void            launcher(t_ctol *uni);
void            init(t_ctol *uni);
void            hooks(t_ctol *uni);
void            set_launcher(t_ctol *uni);
int             set_pause(int keycode, t_ctol *uni);

// fractol.c functions :
void            julia(int x, int y, t_ctol *uni);
void            mandelbrot(int x, int y, t_ctol *uni);
void            burningship(int x, int y, t_ctol *);
int             clear_window(t_ctol *uni);

// mouse_hooks.c functions :
int             mouse_hook(int keycode, int x, int y, t_ctol *uni);
int             motion_notify(int x, int y, t_ctol *uni);

// key_hooks.c functions
int             key_press(int keycode, t_ctol *uni);
int             key_release(int keycode, t_ctol *uni);
int             loop_hook(t_ctol *uni);

// draw.c functions :
void          pixel_put(int x, int y, t_ctol   *uni, t_color color);
void          palette(int x, int y, t_ctol *uni);
void          pick_a_color(t_ctol *uni);

#endif
