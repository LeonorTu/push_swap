/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtu <jtu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 17:55:46 by jtu               #+#    #+#             */
/*   Updated: 2024/01/30 11:08:44 by jtu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_node(t_stack **stack)
{
	t_stack	*temp;

	if (!*stack || !(*stack)->next)
		return ;
	temp = *stack;
	*stack = (*stack)->next;
	temp->next = (*stack)->next;
	(*stack)->next = temp;
}

void	sa(t_stack **a, bool checker)
{
	swap_node(a);
	if (!checker)
		write(1, "sa\n", 3);
}

void	sb(t_stack **b, bool checker)
{
	swap_node(b);
	if (!checker)
		write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b, bool checker)
{
	swap_node(a);
	swap_node(b);
	if (!checker)
		write(1, "ss\n", 3);
}
