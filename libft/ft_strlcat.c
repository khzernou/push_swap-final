/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khzernou <khzernou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 16:05:11 by khzernou          #+#    #+#             */
/*   Updated: 2025/11/23 17:19:19 by khzernou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	src_size;
	size_t	dst_size;

	dst_size = 0;
	src_size = 0;
	while (dst_size < size && dst[dst_size] != '\0')
		dst_size++;
	while (src[src_size] && (dst_size + src_size + 1) < size)
	{
		dst[dst_size + src_size] = src[src_size];
		src_size++;
	}
	if (dst_size < size)
		dst[dst_size + src_size] = '\0';
	return (dst_size + ft_strlen(src));
}
