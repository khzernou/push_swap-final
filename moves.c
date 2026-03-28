/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khzernou <khzernou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 17:12:33 by khzernou          #+#    #+#             */
/*   Updated: 2026/03/28 16:57:00 by khzernou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack_node **a, char *op)
{
	swap(a, op);
}

void	pa(t_stack_node **a, t_stack_node **b, bool print)
{
	if (print)
		push(a, b, "pa");
	else
		push(a, b, NULL);
}

void	pb(t_stack_node **b, t_stack_node **a, bool print)
{
	if (print)
		push(b, a, "pb");
	else
		push(b, a, NULL);
}

void	rb(t_stack_node **b, char *op)
{
	rotate(b, op);
}

void	rrb(t_stack_node **b, char *op)
{
	rev_rotate(b, op);
}
