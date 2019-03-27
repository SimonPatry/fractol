/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcordeno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 10:09:20 by lcordeno          #+#    #+#             */
/*   Updated: 2018/11/15 17:07:12 by lcordeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	unsigned long long	output;
	int					i;
	int					minus;

	output = 0;
	i = 0;
	minus = 1;
	while ((str[i] == ' ') || (str[i] == '\t') || (str[i] == '\n') ||
	(str[i] == '\v') || (str[i] == '\r') || (str[i] == '\f'))
		str++;
	if (*str == '-')
		minus = -1;
	if (*str == '-' || str[i] == '+')
		str++;
	while (str[i] && (str[i] >= '0') && (str[i] <= '9'))
	{
		output = output * 10;
		output += str[i] - '0';
		i++;
	}
	if (output > 9223372036854775807 || i > 19)
		return (minus < 0 ? 0 : -1);
	return (output * minus);
}
