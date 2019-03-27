/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcordeno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 10:54:51 by lcordeno          #+#    #+#             */
/*   Updated: 2018/11/16 15:44:46 by lcordeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char	**stab;
	int		i;
	int		j;
	int		size;

	i = 0;
	j = 0;
	if (!s || !(stab = (char**)malloc(sizeof(char*) *
	(ft_count_words((char*)s, c) + 1))))
		return (NULL);
	while (i < ft_count_words((char*)s, c))
	{
		size = 0;
		while (s[j] == c)
			j++;
		while (s[j] != c && s[j] != '\0')
		{
			j++;
			size++;
		}
		stab[i++] = ft_strsub((char*)s, j - size, size);
	}
	stab[i] = 0;
	return (stab);
}
