/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buddhabrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 13:02:39 by sipatry           #+#    #+#             */
/*   Updated: 2019/03/26 16:27:50 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	set_up_buddhabrot(t_env *env)
{
	env->w = 1350;
	env->h = 1000;
	env->frac = 3;
	env->zoom = 400.0;
	env->z.mix = -1.7;
	env->z.miy = -1.7;
	env->z.max = 1;
	env->z.may = 0.6;
	env->set.n = 0;
	env->set.n_min = 20;
	env->set.n_max = 300;
	env->pas= 2.7 / 500;
	env->b_check = 1;
	env->chose_n = 0;
}

void	*buddhabrot(void *param)
{
	t_env	*env;
	t_float c;

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
			if (env->set.n > env->set.n_min && env->set.n < env->set.n_max)
			{
				env->set.n = 0;
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
					env->img_y = (int)((env->z.x - env->z.mix) * env->zoom);
					env->img_x = (int)((env->z.y - env->z.miy) * env->zoom);
					if ((env->img_x < env->w && env->img_x >= 0)
						&& (env->img_y < env->h && env->img_y >= 0))
						set_colors_buddha(env);
				}
			}
			env->p.x++;
			env->set.n = 0;
		}
		env->p.y++;
	}
	return (0);
}
