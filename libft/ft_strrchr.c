/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khzernou <khzernou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 11:29:31 by khzernou          #+#    #+#             */
/*   Updated: 2025/11/26 17:08:19 by khzernou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int a)
{
	size_t	c;
	char	*last;
	char	char_to_find;
	size_t	len;

	char_to_find = (char)a;
	last = NULL;
	len = ft_strlen(s);
	c = 0;
	while (c <= len)
	{
		if (s[c] == char_to_find)
		{
			last = (char *)&s[c];
		}
		c++;
	}
	return (last);
}
