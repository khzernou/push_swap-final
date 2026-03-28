/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khzernou <khzernou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 16:50:53 by khzernou          #+#    #+#             */
/*   Updated: 2025/12/30 17:59:50 by khzernou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex_print_ull(unsigned long long n, char *base)
{
	int	len;
	int	res;

	len = 0;
	if (n >= 16)
	{
		res = ft_hex_print_ull(n / 16, base);
		if (res == -1)
			return (-1);
		len += res;
	}
	res = ft_c_print(base[n % 16]);
	if (res == -1)
		return (-1);
	len += res;
	return (len);
}

int	ft_p_print(void *ptr)
{
	unsigned long long	addr;
	int					len;
	int					res;

	if (!ptr)
		return (write(1, "(nil)", 5));
	addr = (unsigned long long)ptr;
	len = 0;
	res = write(1, "0x", 2);
	if (res == -1)
		return (-1);
	len += res;
	res = ft_hex_print_ull(addr, "0123456789abcdef");
	if (res == -1)
		return (-1);
	len += res;
	return (len);
}
