/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 14:18:25 by sipatry           #+#    #+#             */
/*   Updated: 2019/03/26 18:23:42 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int		strdiff(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	if (i < ft_strlen(s2))
		return (0);
	return (1);
}

void	get_fractal(char *str, t_env *env)
{
	char	s1[] = "julia";
	char	s2[] = "mandelbrot";
	char	s3[] = "buddhabrot";
	int	x;

	if ((x = strdiff(str, s1)) == 1)
		set_up_env(env, 1);
	else if ((x = strdiff(str, s2)) == 1)
		set_up_env(env, 2);
	else if ((x = strdiff(str, s3)) == 1)
		set_up_env(env, 3);
	else
	{
		env->frac = 0;
		ft_putstr("Wrong name of fractal\n");
	}
}

void	set_up_env(t_env *env, int x)
{
	if (x == 1)
		set_up_julia(env);
	else if (x == 2)
		set_up_mandelbrot(env);
	else if (x == 3)
		set_up_buddhabrot(env);
	env->move_x = 0;
	env->move_y = 0;
}

void	set_color(t_env *env)
{
	if (env->set.n == env->set.n_max && (env->img_x < env->w)
		&& (env->img_y < env->h))
		env->set.str[(env->img_x) + (env->img_y * env->w)] = 0;
	else if (env->p.x < env->w && env->p.y < env->h)
		env->set.str[(env->img_x) + (env->img_y * env->w)] = (blue(env) + red(env));
}

void	set_colors_buddha(t_env *env)
{
	env->set.str[env->img_x + (env->img_y * env->w)] += 20 * 256; 
}

void	draw_fractal(t_env *env)
{
	env->set.img_ptr = mlx_new_image(env->set.mlx_ptr, env->w, env->h);
	env->set.str = (unsigned int*)mlx_get_data_addr(env->set.img_ptr,
			&(env->set.bit_per_pixel), &(env->set.size_line), &(env->set.edian));
	if (env->frac == 1)
		init_thread(env, &julia);
	else if (env->frac == 2)
		init_thread(env, &mandelbrot);
	else if (env->frac == 3)
		init_thread(env, &buddhabrot);
	mlx_put_image_to_window(env->set.mlx_ptr, env->set.win_ptr, env->set.img_ptr, 0, 0);
}
