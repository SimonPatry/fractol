/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 11:52:27 by sipatry           #+#    #+#             */
/*   Updated: 2019/03/26 19:11:14 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	hooks(t_env *env)
{
	mlx_hook(env->set.win_ptr, 17, 0, close_w, (void *)0);
	mlx_hook(env->set.win_ptr, KEYPRESS, KEYPRESSMASK, key_press, env);
	if (env->b_check == 0)
		mlx_hook(env->set.win_ptr, BUTTONPRESS, BUTTONPRESSMASK, mouse_press1, env);
	if (env->b_check == 1)
		mlx_hook(env->set.win_ptr, BUTTONPRESS, BUTTONPRESSMASK, mouse_press2, env);
	mlx_hook(env->set.win_ptr, MOTIONNOTIFY, BUTTON1MOTIONMASK, mouse_move, env);
	mlx_hook(env->set.win_ptr, BUTTONRELEASE, BUTTONRELEASEMASK, mouse_release, env);
}

int		mouse_press1(int button, int x, int y,  t_env *env)
{
	if (button == SCROLLUP_KEY)
	{
		env->z.mix = (x / env->zoom + env->z.mix) - (x / (env->zoom * 1.5));
		env->z.miy = (y / env->zoom + env->z.miy) - (y / (env->zoom * 1.5));
		env->zoom *= 1.5;
		env->set.n_max += 4;
		draw_fractal(env);
	}
	if (button == SCROLLDOWN_KEY)
	{
		env->z.mix = (x / env->zoom + env->z.mix) - (x / (env->zoom / 1.5));
		env->z.miy = (y / env->zoom + env->z.miy) - (y / (env->zoom / 1.5));
		env->zoom /= 1.5;
		if (env->set.n_max > 4 && env->zoom > 25.0)
			env->set.n_max -= 4;
		draw_fractal(env);
	}
	return (0);
}

int		mouse_release(int button, int x, int y, t_env *env)
{
	if (button == BUT1_KEY)
		env->move = env->move ? 0 : 1;
	return (0);
}

int		mouse_move(int x, int y, t_env *env)
{

	if (env->frac == 1 && env->move == 1)
	{
		env->j_x = (double)y / (double)env->w;
		env->j_y = (double)x / (double)env->h;
		env->c.x = env->j_x;
		env->c.y = env->j_y;
		draw_fractal(env);
	}
	return (0);
}
