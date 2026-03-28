/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khzernou <khzernou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 17:33:10 by khzernou          #+#    #+#             */
/*   Updated: 2026/03/27 17:36:39 by khzernou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack_node **a, char *op)
{
	rotate(a, op);
}

void	rr(t_stack_node **a, t_stack_node **b, bool print)
{
	rotate(a, NULL);
	rotate(b, NULL);
	if (print)
		ft_printf("rr\n");
}

void	rra(t_stack_node **a, char *op)
{
	rev_rotate(a, op);
}

void	rrr(t_stack_node **a, t_stack_node **b, bool print)
{
	rev_rotate(a, NULL);
	rev_rotate(b, NULL);
	if (print)
		ft_printf("rrr\n");
}
