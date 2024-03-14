/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtu <jtu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 16:25:40 by jtu               #+#    #+#             */
/*   Updated: 2024/03/14 21:00:49 by jtu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	push_median(t_stack	**a, t_stack **b, t_values *values)
{
	t_stack	*temp;
	int		i;
	int		len;

	temp = *a;
	i = 0;
	while (temp->value != values->median)
	{
		temp = temp->next;
		i++;
	}
	len = stack_len(*a);
	if (i <= len - i)
	{
		while (i--)
			ra(a, false);
	}
	else
	{
		i = len - i;
		while (i--)
			rra(a, false);
	}
	pb(a, b, false);
}

void	push_a2b(t_stack **a, t_stack **b, t_values *values)
{
	int	len;

	len = stack_len(*a);
	if (len == 5)
		return ;
	while (len--)
	{
		if (!max_value((*a)->value, values))
		{
			pb(a, b, false);
			if ((*b)->value > values->median)
				rb(b, false);
		}
		else
			ra(a, false);
	}
}

static void	move_min2(t_stack **a, t_values *values, t_moves *best_moves)
{
	t_stack	*temp;
	int		i;
	int		len_a;

	temp = *a;
	i = 0;
	while (temp->value != values->min)
	{
		temp = temp->next;
		i++;
	}
	len_a = stack_len(*a);
	if (i <= len_a - i)
		while (i--)
			ra(a, false);
	else
	{
		i = len_a - i;
		while (i--)
			rra(a, false);
	}
	free(best_moves);
}

void	push_b2a(t_stack **a, t_stack **b, t_values *values)
{
	t_moves	*best_moves;
	int		len_b;

	best_moves = malloc(sizeof(t_moves));
	if (!best_moves)
		free_everything(a, b, values, best_moves);
	init_moves(best_moves);
	len_b = stack_len(*b);
	while (len_b--)
	{
		calculate_best_moves(a, b, values, best_moves);
		apply_best_moves(a, b, best_moves);
		best_moves->total = INT_MAX;
	}
	move_min2(a, values, best_moves);
}

void	push_swap(t_stack **a, t_stack **b)
{
	t_values	*values;
	t_stack		*sorted_stack;

	values = malloc(sizeof(t_values));
	if (!values)
	{
		free_stack(a);
		free_stack(b);
	}
	sorted_stack = stack_copy(*a);
	quick_sort(sorted_stack, last_node(&sorted_stack));
	find_values(sorted_stack, values);
	push_median(a, b, values);
	push_a2b(a, b, values);
	if (stack_len(*a) == 4)
		sort_four(a, b);
	else
		sort_five(a, b);
	push_b2a(a, b, values);
	free(values);
}
