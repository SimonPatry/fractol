/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 15:45:21 by sipatry           #+#    #+#             */
/*   Updated: 2019/03/26 17:48:31 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef	FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include "mlx_keycode.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>
# include <math.h>
# include <pthread.h>

typedef struct		s_mlx
{
	void			*img_ptr;
	void			*mlx_ptr;
	void			*win_ptr;
	unsigned int	*str;
	int				bit_per_pixel;
	int				size_line;
	int				edian;
	int				n;
	int				n_min;
	int				n_max;
}					t_mlx;

typedef struct		s_draw
{
	int				x;
	int				y;
}					t_draw;

typedef struct		s_float
{
	double			x;
	double			y;
	double			xx;
	double			yy;
	double			mix;
	double			miy;
	double			max;
	double			may;
}					t_float;

typedef struct		s_env
{
	int				w;
	int				h;
	int				frac;
	int				move;
	double			move_x;
	double			move_y;
	double			pas;
	double			zoom;
	t_draw			p;
	t_mlx			set;
	t_float			z;
	t_float			c;
	double			j_x;
	double			j_y;
	int				img_x;
	int				img_y;
	int				start;
	int				end;
	int				b_check;
	int				chose_n;

}					t_env;

void				get_fractal(char *str, t_env *env);
void				*mandelbrot(void *param);
void				draw_fractal(t_env *env);
void				set_color(t_env *env);
void				set_up_env(t_env *env, int x);
unsigned int		green(t_env *env);
unsigned int		blue(t_env *env);
unsigned int		red(t_env *env);
void				*julia(void *param);
int					close_w(void *param);
int					key_press(int key, t_env *env);
void				hooks(t_env *env);
int					mouse_press1(int button, int x, int y, t_env *env);
int					mouse_press2(int button, int x, int y, t_env *env);
void				set_up_mandelbrot(t_env *env);
void				set_up_julia(t_env *env);
void				set_up_buddhabrot(t_env *env);
void				reset_img(t_env *env);
int					mouse_move(int x, int y, t_env *env);
int					mouse_release(int button, int x, int y, t_env *env);
void				*buddhabrot(void *param);
void				set_colors_buddha(t_env *env);
void				change_n(t_env *env, int key);
void				init_thread(t_env *env, void *(*function)(void *));
void				switch_n(t_env *env, int key);

#endif
