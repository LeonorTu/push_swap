/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtu <jtu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:56:50 by jtu               #+#    #+#             */
/*   Updated: 2024/02/01 13:54:18 by jtu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include "./libft/get_next_line/get_next_line_bonus.h"
# include <stdbool.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}	t_stack;

typedef struct s_moves
{
	int	nra;
	int	nrb;
	int	nrr;
	int	nrra;
	int	nrrb;
	int	nrrr;
	int	total;
}	t_moves;

typedef struct s_values
{
	int	median;
	int	min;
	int	max1;
	int	max2;
	int	max3;
	int	max4;
	int	max5;
}	t_values;

// Errors handling
int		invalid_argv(char *str);
int		duplicated_argv(t_stack *stack, int n);
void	free_stack(t_stack **stack);
void	free_var(t_stack **stack);
void	free_everything(t_stack **a, t_stack **b, t_values *values, \
t_moves *best_moves);
void	free_array(char **arr);

// Initialization
void	init_moves(t_moves *moves);
void	init_stack(t_stack **stack, char **argv, int argc);

// Stack util
void	add_node(t_stack **stack, int n);
bool	stack_sorted(t_stack *stack);
int		stack_len(t_stack *stack);
t_stack	*last_node(t_stack **stack);
void	swap_node(t_stack **stack);
void	rotate_stack(t_stack **stack);
void	reverse_rotate_stack(t_stack **stack);
void	push_node(t_stack **dst, t_stack **src);
t_stack	*find_max(t_stack *stack);
t_stack	*find_min(t_stack *stack);
int		max_value(int n, t_values *values);
t_stack	*stack_copy(const t_stack *stack);

// Commands
void	pa(t_stack **a, t_stack **b, bool checker);
void	pb(t_stack **a, t_stack **b, bool checker);
void	sa(t_stack **b, bool checker);
void	sb(t_stack **b, bool checker);
void	ss(t_stack **a, t_stack **b, bool checker);
void	ra(t_stack **a, bool checker);
void	rb(t_stack **b, bool checker);
void	rr(t_stack **a, t_stack **b, bool checker);
void	rra(t_stack **a, bool checker);
void	rrb(t_stack **b, bool checker);
void	rrr(t_stack **a, t_stack **b, bool checker);

// Algorithms
void	sort_stack(t_stack **a, t_stack **b);
void	push_swap(t_stack **a, t_stack **b);
void	find_values(t_stack *stack, t_values *values);
void	push_median(t_stack	**a, t_stack **b, t_values *values);
void	sort_three(t_stack **a);
void	sort_four(t_stack **a, t_stack **b);
void	sort_five(t_stack **a, t_stack **b);
void	quick_sort(t_stack *head, t_stack *tail);
void	calculate_best_moves(t_stack **a, t_stack **b, t_values \
*values, t_moves *best_moves);
void	apply_best_moves(t_stack **a, t_stack **b, t_moves *best_moves);
int		count_bm(t_moves *best_moves);
void	copy_best_moves(t_moves *best_moves, t_moves *best_moves_temp);

// Bonus
void	parse_cmd(t_stack **a, t_stack **b);
void	apply_cmd(t_stack **a, t_stack **b, char *cmd);

#endif
