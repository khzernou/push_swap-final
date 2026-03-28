/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cs_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khzernou <khzernou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 15:53:12 by khzernou          #+#    #+#             */
/*   Updated: 2025/12/31 17:16:41 by khzernou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_s_print(char *s)
{
	int	res;
	int	count;

	count = 0;
	if (s == NULL)
	{
		res = write(1, "(null)", 6);
		if (res == -1)
			return (-1);
		return (6);
	}
	while (s[count])
	{
		res = ft_c_print(s[count]);
		if (res == -1)
			return (-1);
		count++;
	}
	return (count);
}

int	ft_c_print(int c)
{
	int	res;

	res = write(1, &c, 1);
	if (res == -1)
		return (-1);
	return (1);
}
