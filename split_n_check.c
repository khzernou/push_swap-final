/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_n_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khzernou <khzernou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 19:25:10 by khzernou          #+#    #+#             */
/*   Updated: 2026/03/30 15:36:58 by khzernou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//check if string is only digit & a sign
int	error_syntax(char *str_n)
{
	int	i;

	i = 0;
	if (!(str_n[i] == '+' || str_n[i] == '-'
			|| (str_n[i] >= '0' && str_n[i] <= '9')))
		return (1);
	if ((str_n[i] == '+' || str_n[i] == '-')
		&& !(str_n[i + 1] >= '0' && str_n[i + 1] <= '9'))
		return (1);
	while (str_n[++i])
	{
		if (!(str_n[i] >= '0' && str_n[i] <= '9'))
			return (1);
	}
	return (0);
}

// check if duplicate
int	error_duplicate(t_stack_node *a, int n)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->nbr == n)
			return (1);
		a = a->next;
	}
	return (0);
}

// cleanup function
void	free_stack(t_stack_node **stack)
{
	t_stack_node	*tmp;
	t_stack_node	*current;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

//write error on fd
void	free_errors(t_stack_node **a)
{
	free_stack(a);
	write(2, "Error\n", 6);
	exit(1);
}

static void	append_node(t_stack_node **stack, int n)
{
	t_stack_node	*node;
	t_stack_node	*last_node;

	if (!stack)
		return ;
	node = malloc(sizeof(t_stack_node));
	if (!node)
		return ;
	node->next = NULL;
	node->nbr = n;
	if (!(*stack))
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

void	init_stack_a(t_stack_node **a, char **argv)
{
	long	n;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (error_syntax(argv[i]))
			free_errors(a);
		n = ft_atol(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			free_errors(a);
		if (error_duplicate(*a, (int)n))
			free_errors(a);
		append_node(a, (int)n);
		i++;
	}
}
