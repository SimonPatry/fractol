/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcordeno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 17:42:51 by lcordeno          #+#    #+#             */
/*   Updated: 2019/03/25 18:55:24 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t i;
	char	*str;
	const char	*source;

	str = dst;
	source = src;
	i = 0;
	while (i < n)
	{
		str[i] = source[i];
		i++;
	}
	return (dst);
}
