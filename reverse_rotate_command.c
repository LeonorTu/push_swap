/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_command.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtu <jtu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 17:54:36 by jtu               #+#    #+#             */
/*   Updated: 2024/01/30 11:07:48 by jtu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_stack(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*last;

	if (!*stack || !(*stack)->next || !(*stack)->next->next)
		return ;
	temp = *stack;
	while ((*stack)->next->next)
		*stack = (*stack)->next;
	last = (*stack)->next;
	(*stack)->next = NULL;
	last->next = temp;
	*stack = last;
}

void	rra(t_stack **a, bool checker)
{
	reverse_rotate_stack(a);
	if (!checker)
		write(1, "rra\n", 4);
}

void	rrb(t_stack **b, bool checker)
{
	reverse_rotate_stack(b);
	if (!checker)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b, bool checker)
{
	reverse_rotate_stack(a);
	reverse_rotate_stack(b);
	if (!checker)
		write(1, "rrr\n", 4);
}
