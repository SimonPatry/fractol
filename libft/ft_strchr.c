/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcordeno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 17:04:25 by lcordeno          #+#    #+#             */
/*   Updated: 2018/11/15 18:30:36 by lcordeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	while (s[i])
	{
		if ((char)c == s[i])
			return ((char*)&s[i]);
		i++;
	}
	if ((char)c == '\0')
		return ((char*)&s[i]);
	else
		return (NULL);
}
