/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtu <jtu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 17:53:18 by jtu               #+#    #+#             */
/*   Updated: 2024/01/30 11:08:58 by jtu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_stack(t_stack **stack)
{
	t_stack	*temp;

	if (!*stack || !(*stack)->next)
		return ;
	temp = *stack;
	*stack = last_node(stack);
	(*stack)->next = temp;
	*stack = temp->next;
	temp->next = NULL;
}

void	ra(t_stack **a, bool checker)
{
	rotate_stack(a);
	if (!checker)
		write(1, "ra\n", 3);
}

void	rb(t_stack **b, bool checker)
{
	rotate_stack(b);
	if (!checker)
		write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b, bool checker)
{
	rotate_stack(a);
	rotate_stack(b);
	if (!checker)
		write(1, "rr\n", 3);
}
