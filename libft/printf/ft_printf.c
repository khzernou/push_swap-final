/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khzernou <khzernou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 17:01:24 by khzernou          #+#    #+#             */
/*   Updated: 2025/12/16 17:21:56 by khzernou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_check(const char **format, va_list *arg)
{
	int	res;

	(*format)++;
	if (!**format)
		return (0);
	res = ft_cases(**format, arg);
	if (res == -1)
		return (-1);
	(*format)++;
	return (res);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		count;
	int		res;

	va_start(arg, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
			res = ft_check(&format, &arg);
		else
		{
			res = ft_c_print(*format);
			format++;
		}
		if (res == -1)
			return (va_end(arg), -1);
		count += res;
	}
	return (va_end(arg), count);
}
