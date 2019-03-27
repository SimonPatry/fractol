/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcordeno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 18:04:54 by lcordeno          #+#    #+#             */
/*   Updated: 2018/11/13 16:30:08 by lcordeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dst, const char *src)
{
	int i;
	int srclength;
	int dstlength;

	i = 0;
	srclength = 0;
	dstlength = 0;
	while (src[srclength] != '\0')
		srclength++;
	while (i < srclength)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
