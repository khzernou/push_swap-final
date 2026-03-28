/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khzernou <khzernou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 15:47:18 by khzernou          #+#    #+#             */
/*   Updated: 2025/12/17 16:05:40 by khzernou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_u_print(unsigned long n)
{
	int	len;
	int	res;

	len = 0;
	if (n >= 10)
	{
		res = ft_u_print(n / 10);
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
