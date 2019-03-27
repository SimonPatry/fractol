/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 17:34:19 by sipatry           #+#    #+#             */
/*   Updated: 2019/03/26 15:18:36 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	init_thread(t_env *env, void *(*function)(void *))
{
	pthread_t thread[5];
	t_env fracs[5];
	int	i;
	i = 0;
	(void)function;

	while (i < 5)
	{
		ft_memcpy(&fracs[i], env, sizeof(t_env));
		fracs[i].start = env->w / 5 * i;
		fracs[i].end = env->w / 5 * (i + 1);
		pthread_create(&thread[i], NULL, function, &fracs[i]);
		i++;
	}
	while (i-- > 0)
		pthread_join(thread[i], NULL);
}
