/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcordeno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 19:30:26 by lcordeno          #+#    #+#             */
/*   Updated: 2018/11/16 15:49:30 by lcordeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = ft_strlen(src);
	j = ft_strlen(dst);
	k = 0;
	if (size <= j)
		return (i + size);
	while (k < (size - j - 1) && src[k])
	{
		dst[j + k] = src[k];
		k++;
	}
	dst[j + k] = '\0';
	return (i + j);
}
