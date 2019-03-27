/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcordeno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 13:40:31 by lcordeno          #+#    #+#             */
/*   Updated: 2018/11/16 09:55:34 by lcordeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_itoa(int n)
{
	char			*s;
	unsigned int	nb;
	int				count;
	int				sign;

	nb = n;
	sign = 0;
	count = ft_int_length(n);
	if (!(s = (char*)malloc(sizeof(char) * count + 1)))
		return (NULL);
	s[count] = '\0';
	if (n < 0)
	{
		s[0] = '-';
		nb = -n;
		sign = 1;
	}
	while (count > sign)
	{
		s[--count] = (nb % 10) + 48;
		nb = nb / 10;
	}
	return (s);
}
