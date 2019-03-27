/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcordeno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 10:18:28 by lcordeno          #+#    #+#             */
/*   Updated: 2018/11/15 19:19:39 by lcordeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int i;
	int j;

	i = 0;
	if (s)
	{
		j = ft_strlen(s) - 1;
		while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
			i++;
		if (!s[i])
			return (ft_strdup(""));
		while (s[j] == ' ' || s[j] == '\n' || s[j] == '\t')
			j--;
		return (ft_strsub(s, i, j - i + 1));
	}
	return (0);
}
