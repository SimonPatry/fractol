/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 11:13:22 by sipatry           #+#    #+#             */
/*   Updated: 2019/03/26 17:50:04 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	set_up_mandelbrot(t_env *env)
{
	env->w = 1350;
	env->h = 1000;
	env->frac = 2;
	env->zoom = 500.0;
	env->z.miy = -1;
	env->z.mix = -2.1;
	env->z.max = 1;
	env->z.may = 0.6;
	env->set.n = 0;
	env->set.n_max = 30;
	env->pas= 2.7 / 500;
	env->b_check = 0;
	env->chose_n = 1;
}

void	*mandelbrot(void *param)
{
	t_float c;
	t_env	*env;

	env = (t_env *)param;	
	env->p.y = 0;
	while (env->p.y < env->h)
	{
		env->p.x = env->start;
		while (env->p.x < env->end)
		{
			c.x = (env->p.x / env->zoom) + env->z.mix + env->move_x;
			c.y = (env->p.y / env->zoom) + env->z.miy + env->move_y;
			env->z.x = 0;
			env->z.y = 0;
			while (env->z.x * env->z.x + env->z.y * env->z.y < 4
			&& env->set.n < env->set.n_max)
			{
				env->z.xx = env->z.x * env->z.x - env->z.y * env->z.y;
				env->z.yy = 2 * env->z.x * env->z.y;
				env->z.x = (env->z.xx) + c.x;
				env->z.y = env->z.yy + c.y;
				env->set.n++;
			}
			env->img_x = env->p.x;
			env->img_y = env->p.y;
			set_color(env);
			env->p.x++;
			env->set.n = 0;
		}
		env->p.y++;
	}
	return (0);
}
