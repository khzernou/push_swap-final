/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_di_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khzernou <khzernou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 15:53:10 by khzernou          #+#    #+#             */
/*   Updated: 2025/12/30 20:08:06 by khzernou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_di_print(long n)
{
	int	len;
	int	res;

	len = 0;
	if (n < 0)
	{
		res = ft_c_print('-');
		if (res == -1)
			return (-1);
		len += res;
		n = -n;
	}
	if (n >= 10)
	{
		res = ft_di_print(n / 10);
		if (res == -1)
			return (-1);
		len += res;
	}
	res = ft_c_print(n % 10 + '0');
	if (res == -1)
		return (-1);
	len += res;
	return (len);
}
