/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khzernou <khzernou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 16:40:08 by khzernou          #+#    #+#             */
/*   Updated: 2025/11/06 16:00:10 by khzernou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	a;
	size_t	src_len;

	src_len = ft_strlen(src);
	if (dstsize == 0)
		return (ft_strlen(src));
	a = 0;
	while (src[a] != '\0' && a < dstsize - 1)
	{
		dst[a] = src[a];
		a++;
	}
	dst[a] = '\0';
	return (src_len);
}
