/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khzernou <khzernou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 12:47:03 by khzernou          #+#    #+#             */
/*   Updated: 2025/11/26 18:01:08 by khzernou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_digit(long n)
{
	int	count;

	if (n == 0)
		return (1);
	count = 0;
	if (n < 0)
		n = -n;
	while (n > 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

static void	fill_and_sign(char *str, long n, int index, int is_neg)
{
	while (n > 0)
	{
		str[index] = (n % 10) + '0';
		n = n / 10;
		index--;
	}
	if (is_neg)
		str[0] = '-';
}

char	*ft_itoa(int n)
{
	char	*str;
	long	nb_long;
	int		is_neg;
	int		digit_count;
	int		char_count;

	nb_long = n;
	is_neg = (nb_long < 0);
	if (is_neg)
		nb_long = -nb_long;
	digit_count = get_digit(nb_long);
	char_count = digit_count;
	if (is_neg)
		char_count++;
	str = (char *)malloc(sizeof(char) * (char_count + 1));
	if (!str)
		return (NULL);
	str[char_count] = '\0';
	if (n == 0)
	{
		str[0] = '0';
		return (str);
	}
	fill_and_sign(str, nb_long, char_count - 1, is_neg);
	return (str);
}
