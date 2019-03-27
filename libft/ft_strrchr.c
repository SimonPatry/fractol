/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcordeno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 17:17:32 by lcordeno          #+#    #+#             */
/*   Updated: 2018/11/16 11:22:24 by lcordeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	if ((char)c == '\0')
		return ((char*)&s[i]);
	while (i--)
	{
		if ((char)c == s[i])
			return ((char*)&s[i]);
	}
	return (NULL);
}
