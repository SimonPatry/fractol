/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 14:35:48 by sipatry           #+#    #+#             */
/*   Updated: 2019/03/26 17:42:25 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	set_up_julia(t_env *env)
{
	env->w = 1200;
	env->h = 1200;
	env->frac = 1;
	env->zoom = 400.0;
	env->z.mix = -1.5;
	env->z.miy = -1.5;
	env->z.max = 1.5;
	env->z.may = 1.5;
	env->set.n = 0;
	env->set.n_max = 30;
	env->c.x = 0.285;
	env->c.y = 0.01;
	env->move = 0;
	env->b_check = 1;
	env->chose_n = 1;
}

void	*julia(void *param)
{
	t_env *env;

	env = (t_env *)param;
	env->p.y = 0;
	while (env->p.y < env->h)
	{
		env->p.x = env->start;
		while (env->p.x < env->end)
		{
			env->z.x = (env->p.x / env->zoom) + env->z.mix + env->move_x;
			env->z.y = (env->p.y / env->zoom) + env->z.miy + env->move_y;
			while (env->z.x * env->z.x + env->z.y * env->z.y < 4
					&& env->set.n < env->set.n_max)
			{
				env->z.xx = env->z.x * env->z.x - env->z.y * env->z.y;
				env->z.yy = 2 * env->z.x * env->z.y;
				env->z.x = env->z.xx + env->c.x;
				env->z.y = env->z.yy + env->c.y;
				env->set.n++;
			}
			env->img_x = env->p.y;
			env->img_y = env->p.x;
			set_color(env);
			env->p.x++;
			env->set.n = 0;
		}
		env->p.y++;
	}
	return (0);
}
