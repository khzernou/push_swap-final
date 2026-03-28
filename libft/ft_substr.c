/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khzernou <khzernou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 15:43:47 by khzernou          #+#    #+#             */
/*   Updated: 2025/11/26 17:49:10 by khzernou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const	*s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	s_len;
	size_t	act_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	act_len = s_len - start;
	if (start >= s_len)
	{
		sub = (char *)malloc(sizeof(char) * 1);
		if (!sub)
			return (NULL);
		sub[0] = '\0';
		return (sub);
	}
	if (len < act_len)
		act_len = len;
	sub = (char *)malloc(sizeof(char) * (act_len + 1));
	if (!sub)
		return (NULL);
	ft_memcpy(sub, s + start, act_len);
	sub[act_len] = '\0';
	return (sub);
}
