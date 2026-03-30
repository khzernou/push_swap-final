/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khzernou <khzernou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 17:15:02 by khzernou          #+#    #+#             */
/*   Updated: 2026/03/30 15:34:36 by khzernou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_len(t_stack_node *stack)
{
	int	count;

	if (!stack)
		return (0);
	count = 0;
	while (stack)
	{
		stack = stack->next;
		count++;
	}
	return (count);
}

bool	stack_sorted(t_stack_node *stack)
{
	if (!stack)
		return (true);
	while (stack->next)
	{
		if (stack->nbr > stack->next->nbr)
			return (false);
		stack = stack->next;
	}
	return (true);
}

t_stack_node	*get_cheapest(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	prep_for_push(t_stack_node **stack, t_stack_node *top_node, char name)
{
	while (*stack != top_node)
	{
		if (name == 'a')
		{
			if (top_node->above_median)
				ra(stack, "ra");
			else
				rra(stack, "rra");
		}
		else if (name == 'b')
		{
			if (top_node->above_median)
				rb(stack, "rb");
			else
				rrb(stack, "rrb");
		}
	}
}

void	min_on_top(t_stack_node **a)
{
	t_stack_node	*smallest;

	smallest = find_min(*a);
	while ((*a)->nbr != smallest->nbr)
	{
		if (smallest->above_median)
			ra(a, "ra");
		else
			rra(a, "rra");
	}
}
