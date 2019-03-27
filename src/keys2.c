/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 16:56:48 by sipatry           #+#    #+#             */
/*   Updated: 2019/03/26 17:48:07 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	change_n(t_env *env, int key)
{
	
	if (env->chose_n == 0)
	{
		if (key == NKPL_KEY)
			env->set.n_min += 5;
		if (key == NKMN_KEY)
			env->set.n_min -= 5;
	}
	if (env->chose_n == 1)
	{
		if (key == NKPL_KEY)
			env->set.n_max += 5;
		if (key == NKMN_KEY)
			env->set.n_max -= 5;
	}
	draw_fractal(env);
}

void	switch_n(t_env *env, int key)
{
	env->chose_n = env->chose_n ? 0 : 1;
}

int		mouse_press2(int button, int x, int y,  t_env *env)
{
	if (button == SCROLLUP_KEY)
	{
		env->z.mix = (y / env->zoom + env->z.mix) - (y / (env->zoom * 1.1));
		env->z.miy = (x / env->zoom + env->z.miy) - (x / (env->zoom * 1.1));
		env->zoom *= 1.1;
		env->set.n_max += 4;
		draw_fractal(env);
	}
	if (button == SCROLLDOWN_KEY)
	{
		env->z.mix = (y / env->zoom + env->z.mix) - (y / (env->zoom / 1.1));
		env->z.miy = (x / env->zoom + env->z.miy) - (x / (env->zoom / 1.1));
		env->zoom /= 1.1;
		if (env->set.n_max > 4 && env->zoom > 25.0)
			env->set.n_max -= 4;
		draw_fractal(env);
	}
	return (0);
}
