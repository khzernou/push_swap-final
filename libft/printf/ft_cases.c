/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cases.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khzernou <khzernou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 16:02:01 by khzernou          #+#    #+#             */
/*   Updated: 2025/12/17 16:56:52 by khzernou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_cases(char c, va_list *arg)
{
	if (c == 'd' || c == 'i')
		return (ft_di_print(va_arg(*arg, int)));
	else if (c == 'c')
		return (ft_c_print(va_arg(*arg, int)));
	else if (c == 's')
		return (ft_s_print(va_arg(*arg, char *)));
	else if (c == 'u')
		return (ft_u_print((unsigned int)va_arg(*arg, unsigned int)));
	else if (c == 'x')
		return (ft_x_print((unsigned int)va_arg(*arg, unsigned int)));
	else if (c == 'X')
		return (ft_xupper_print((unsigned int)va_arg(*arg, unsigned int)));
	else if (c == 'p')
		return (ft_p_print(va_arg(*arg, void *)));
	else if (c == '%')
		return (ft_c_print('%'));
	return (0);
}
