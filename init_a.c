/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khzernou <khzernou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 15:58:15 by khzernou          #+#    #+#             */
/*   Updated: 2026/03/27 17:47:26 by khzernou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_target_a(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*curr_b;
	t_stack_node	*target;
	long			match_idx;

	while (a)
	{
		match_idx = LONG_MIN;
		curr_b = b;
		while (curr_b)
		{
			if (curr_b->nbr < a->nbr && curr_b->nbr > match_idx)
			{
				match_idx = curr_b->nbr;
				target = curr_b;
			}
			curr_b = curr_b->next;
		}
		if (match_idx == LONG_MIN)
			a->target_node = find_max(b);
		else
			a->target_node = target;
		a = a->next;
	}
}

void	cost_analysis_a(t_stack_node *a, t_stack_node *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (a)
	{
		if (a->above_median)
			a->push_cost = a->index;
		else
			a->push_cost = len_a - (a->index);
		if (a->target_node->above_median)
			a->push_cost += a->target_node->index;
		else
			a->push_cost += len_b - (a->target_node->index);
		a = a->next;
	}
}

void	init_nodes_a(t_stack_node *a, t_stack_node *b)
{
	current_index(a);
	current_index(b);
	set_target_a(a, b);
	cost_analysis_a(a, b);
	get_cheapest(a);
}
