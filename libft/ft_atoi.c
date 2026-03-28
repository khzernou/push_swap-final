/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khzernou <khzernou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 19:16:51 by khzernou          #+#    #+#             */
/*   Updated: 2026/03/28 18:17:44 by khzernou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_overflow(long long res, int sign_val, int next_digit)
{
	if (sign_val == 1)
	{
		if (res > LLONG_MAX / 10 || (res == LLONG_MAX / 10
				&& next_digit > LLONG_MAX % 10))
			return (-1);
	}
	else
	{
		if (res > LLONG_MIN / -10 || (res == LLONG_MIN / -10
				&& next_digit > LLONG_MIN % -10))
			return (1);
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	int			c;
	int			of_val;
	long long	sign;
	long long	result;

	c = 0;
	sign = 1;
	result = 0;
	while (str[c] == ' ' || (str[c] >= 9 && str[c] <= 13))
		c++;
	if (str[c] == '-' || str[c] == '+')
	{
		if (str[c] == '-')
			sign = -1;
		c++;
	}
	while (str[c] >= '0' && str[c] <= '9')
	{
		of_val = ft_check_overflow(result, sign, str[c] - '0');
		if (of_val != 0)
			return (of_val);
		result = result * 10 + (str[c] - '0');
		c++;
	}
	return ((int)sign * result);
}

long	ft_atol(const char *s)
{
	long	res;
	int		sign;
	int		i;

	res = 0;
	sign = 1;
	i = 0;
	while (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13))
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		res = res * 10 + (s[i] - '0');
		i++;
	}
	return (res * sign);
}
