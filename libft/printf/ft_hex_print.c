/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khzernou <khzernou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 16:09:49 by khzernou          #+#    #+#             */
/*   Updated: 2025/12/31 17:19:50 by khzernou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex_print(unsigned int n, char *base)
{
	int	len;
	int	res;

	len = 0;
	if (n >= 16)
	{
		res = ft_hex_print(n / 16, base);
		if (res == -1)
			return (-1);
		len += res;
	}
	res = write(1, &base[n % 16], 1);
	if (res == -1)
		return (-1);
	len += res;
	return (len);
}

int	ft_x_print(unsigned int n)
{
	return (ft_hex_print(n, "0123456789abcdef"));
}

int	ft_xupper_print(unsigned int n)
{
	return (ft_hex_print(n, "0123456789ABCDEF"));
}
