/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 18:11:40 by sipatry           #+#    #+#             */
/*   Updated: 2019/03/25 14:48:15 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

unsigned int	red(t_env *env)
{
	unsigned int	red;

	red = ((env->set.n * 256 / env->set.n_max) * 256 * 256);
	return (red);
}

unsigned int	green(t_env *env)
{
	unsigned int	green;

	green = ((env->set.n * 256 / env->set.n_max) * 256);
	return (green);
}

unsigned int	blue(t_env *env)
{
	unsigned int	blue;

	blue = ((env->set.n * 256) / env->set.n_max);
	return (blue);
}
