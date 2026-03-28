/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khzernou <khzernou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 19:24:03 by khzernou          #+#    #+#             */
/*   Updated: 2026/03/27 17:18:31 by khzernou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//swap
void	swap(t_stack_node **head, char *op_name)
{
	t_stack_node	*first;
	t_stack_node	*second;

	if (!*head || !(*head)->next)
		return ;
	first = *head;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	*head = second;
	if (op_name)
		ft_printf("%s\n", op_name);
}

//push
void	push(t_stack_node **dst, t_stack_node **src, char *op_name)
{
	t_stack_node	*push_node;

	if (!*src)
		return ;
	push_node = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	push_node->prev = NULL;
	if (!*dst)
	{
		*dst = push_node;
		push_node->next = NULL;
	}
	else
	{
		push_node->next = *dst;
		push_node->next->prev = push_node;
		*dst = push_node;
	}
	if (op_name)
		ft_printf("%s\n", op_name);
}

//rotate
void	rotate(t_stack_node **stack, char *op_name)
{
	t_stack_node	*last_node;
	t_stack_node	*first_node;

	if (!*stack || !(*stack)->next)
		return ;
	first_node = *stack;
	last_node = *stack;
	while (last_node->next)
		last_node = last_node->next;
	*stack = first_node->next;
	(*stack)->prev = NULL;
	last_node->next = first_node;
	first_node->prev = last_node;
	first_node->next = NULL;
	if (op_name)
		ft_printf("%s\n", op_name);
}

//reverse rotate
void	rev_rotate(t_stack_node **stack, char *op_name)
{
	t_stack_node	*last_node;

	if (!*stack || !(*stack)->next)
		return ;
	last_node = *stack;
	while (last_node->next)
		last_node = last_node->next;
	last_node->prev->next = NULL;
	last_node->next = *stack;
	last_node->prev = NULL;
	(*stack)->prev = last_node;
	*stack = last_node;
	if (op_name)
		ft_printf("%s\n", op_name);
}
