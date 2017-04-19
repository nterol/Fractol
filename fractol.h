/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nterol <nterol@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 15:19:53 by nterol            #+#    #+#             */
/*   Updated: 2017/04/19 18:50:33 by nterol           ###   ########.fr       */
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
# define M_LEFT 7
# define M_RIGHT 6
# define PAUSE 49
# define ESC 53
# define PLUS 69
# define MINUS 78
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
  t_color       pal1;
  t_color       pal2
  t_color       begin;
  t_color       end;
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
  double        mu;
  t_fra         env;
  t_key         love;

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

// hooks.c functions :
int             mouse_hook(int keycode, int x, int y, t_ctol *uni);
int             motion_notify(int x, int y, t_ctol *uni);
int             key_press(int keycode, t_ctol *uni);
int             key_release(int keycode, t_ctol *uni);
int             loop_hook(t_ctol *uni);
//int             button_press(int button, int x, int y, t_ctol *uni);

// draw.c functions :
void          pixel_put(int x, int y, t_ctol   *uni, t_color color);
void          palette(int x, int y, t_ctol *uni);

#endif
