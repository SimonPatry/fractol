/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 12:22:25 by sipatry           #+#    #+#             */
/*   Updated: 2019/03/26 18:14:29 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int		main(int ac, char **av)
{
	t_env	env;

	if (ac != 2)
	{
		ft_putstr("wrong number of argument\n");
		return (0);
	}
	get_fractal(av[1], &env);
	if (env.frac == 0)
		return (0);
	env.set.mlx_ptr = mlx_init();
	env.set.win_ptr = mlx_new_window(env.set.mlx_ptr, env.w, env.h, "fractol");
	draw_fractal(&env);
	hooks(&env);
	mlx_loop(env.set.mlx_ptr);
	return (0);
}
