/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_wordtab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcordeno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 12:31:56 by lcordeno          #+#    #+#             */
/*   Updated: 2018/09/20 12:00:29 by lcordeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		ft_sort_wordtab(char **tab)
{
	char	*tmp;
	int		a;
	int		b;

	a = 0;
	while (tab[a + 1])
	{
		b = 0;
		while (tab[a])
			if (tab[a][b] > tab[a + 1][b])
			{
				tmp = tab[a];
				tab[a] = tab[a + 1];
				tab[a + 1] = tmp;
				a = -1;
				break ;
			}
			else if (tab[a][b] == tab[a + 1][b])
				b++;
			else
				break ;
		a++;
	}
}
