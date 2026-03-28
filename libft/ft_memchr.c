/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khzernou <khzernou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 19:06:06 by khzernou          #+#    #+#             */
/*   Updated: 2025/11/27 20:46:57 by khzernou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				ind;
	unsigned char		byte_to_find;
	const unsigned char	*mem_block;

	mem_block = (const unsigned char *)s;
	byte_to_find = (unsigned char)c;
	ind = 0;
	while (ind < n)
	{
		if (mem_block[ind] == byte_to_find)
			return ((void *)(mem_block + ind));
		ind++;
	}
	return (NULL);
}
