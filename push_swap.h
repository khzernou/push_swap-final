/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khzernou <khzernou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 17:44:03 by khzernou          #+#    #+#             */
/*   Updated: 2026/03/30 18:03:05 by khzernou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include "./libft/libft.h"
# include "./libft/printf/ft_printf.h"

typedef struct s_stack_node
{
	int					nbr;
	int					index;
	int					push_cost;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

/* --- Parsing & Errors --- */
long			ft_atol(const char *s);
int				error_syntax(char *str_n);
int				error_duplicate(t_stack_node *a, int n);
void			free_stack(t_stack_node **stack);
void			free_errors(t_stack_node **a);
void			init_stack_a(t_stack_node **a, char **argv);

/* --- Operations --- */
void			sa(t_stack_node **a, char *op);
void			pa(t_stack_node **a, t_stack_node **b, bool print);
void			pb(t_stack_node **b, t_stack_node **a, bool print);
void			ra(t_stack_node **a, char *op);
void			rb(t_stack_node **b, char *op);
void			rr(t_stack_node **a, t_stack_node **b, bool print);
void			rra(t_stack_node **a, char *op);
void			rrb(t_stack_node **b, char *op);
void			rrr(t_stack_node **a, t_stack_node **b, bool print);

/* --- Base Generic Operations --- */
void			swap(t_stack_node **head, char *op_name);
void			push(t_stack_node **dst, t_stack_node **src, char *op_name);
void			rotate(t_stack_node **stack, char *op_name);
void			rev_rotate(t_stack_node **stack, char *op_name);

/* --- Stack Utils --- */
int				stack_len(t_stack_node *stack);
bool			stack_sorted(t_stack_node *stack);
t_stack_node	*find_min(t_stack_node *stack);
t_stack_node	*find_max(t_stack_node *stack);
t_stack_node	*find_last(t_stack_node *stack);
t_stack_node	*get_cheapest(t_stack_node *stack);
void			current_index(t_stack_node *stack);
void			set_cheapest(t_stack_node *stack);

/* --- Algorithm Core --- */
void			sort_three(t_stack_node **a);
void			push_swap(t_stack_node **a, t_stack_node **b);
void			init_nodes_a(t_stack_node *a, t_stack_node *b);
void			init_nodes_b(t_stack_node *a, t_stack_node *b);
void			move_a_to_b(t_stack_node **a, t_stack_node **b);
void			prep_for_push(t_stack_node **s, t_stack_node *n, char name);
void			min_on_top(t_stack_node **a);

#endif