/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khzernou <khzernou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 18:42:41 by khzernou          #+#    #+#             */
/*   Updated: 2025/11/27 19:55:50 by khzernou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*srcs;
	unsigned char	*dest;

	srcs = (unsigned char *)src;
	dest = (unsigned char *)dst;
	if (!srcs && !dest)
		return (NULL);
	while (n)
	{
		*dest = *srcs;
		dest++;
		srcs++;
		n--;
	}
	return (dst);
}
