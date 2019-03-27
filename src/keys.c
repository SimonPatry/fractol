/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 16:34:39 by sipatry           #+#    #+#             */
/*   Updated: 2019/03/26 17:48:10 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	close_w(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

void	move_img_x(t_env *env, int key)
{
	mlx_destroy_image(env->set.mlx_ptr, env->set.img_ptr);
	if (key == RIGHT_KEY)
	{
		env->move_x -= 0.05;
		draw_fractal(env);
	}
	if (key == LEFT_KEY)
	{
		env->move_x += 0.05;
	   draw_fractal(env);	
	}
}

void	move_img_y(t_env *env, int key)
{
	mlx_destroy_image(env->set.mlx_ptr, env->set.img_ptr);
	if (key == UP_KEY)
	{
		env->move_y += 0.05;
		draw_fractal(env);
	}
	if (key == DOWN_KEY)
	{
		env->move_y -= 0.05;
	   draw_fractal(env);	
	}
}

void	reset_img(t_env *env)
{
	set_up_env(env, env->frac);
	draw_fractal(env);
}

int		key_press(int key, t_env *env)
{
	if (key == ESC_KEY)
		exit(1);
	if (key == RIGHT_KEY || key == LEFT_KEY)
		move_img_x(env, key);
	if (key == UP_KEY || key == DOWN_KEY)
		move_img_y(env, key);
	if (key == NKPL_KEY || key == NKMN_KEY)
		change_n(env, key);
	if (key == N_KEY)
		switch_n(env, key);
	if (key == R_KEY)
		reset_img(env);
	return (0);
}
