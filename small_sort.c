/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtu <jtu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 10:26:07 by jtu               #+#    #+#             */
/*   Updated: 2024/02/01 13:56:56 by jtu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **a)
{
	t_stack	*max_node;

	max_node = find_max(*a);
	if (*a == max_node)
		ra(a, false);
	else if ((*a)->next == max_node)
		rra(a, false);
	if ((*a)->value > (*a)->next->value)
		sa(a, false);
}

void	sort_four(t_stack **a, t_stack **b)
{
	t_stack	*min_node;

	if (stack_sorted(*a))
		return ;
	min_node = find_min(*a);
	if (last_node(a) == min_node)
		rra(a, false);
	while (*a != min_node)
		ra(a, false);
	if (stack_sorted(*a))
		return ;
	pb(a, b, false);
	sort_three(a);
	pa(a, b, false);
}

static void	move_min1(t_stack **a, t_stack *stack, t_stack *min_node)
{
	if (stack->next == min_node)
	{
		ra(a, false);
		ra(a, false);
	}
	else if (stack->next->next == min_node)
	{
		rra(a, false);
		rra(a, false);
	}
}

void	sort_five(t_stack **a, t_stack **b)
{
	t_stack	*min_node;
	t_stack	*temp;

	if (stack_sorted(*a))
		return ;
	temp = *a;
	min_node = find_min(temp);
	if (last_node(&temp) == min_node)
		rra(a, false);
	else if (temp->next == min_node)
		ra(a, false);
	else
	{
		temp = temp->next;
		move_min1(a, temp, min_node);
	}
	pb(a, b, false);
	sort_four(a, b);
	pa(a, b, false);
}
