/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtu <jtu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 17:57:02 by jtu               #+#    #+#             */
/*   Updated: 2024/01/31 18:42:05 by jtu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_node(t_stack **dst, t_stack **src)
{
	t_stack	*first_node;

	if (!*src)
		return ;
	first_node = *src;
	*src = (*src)->next;
	if (*dst)
	{
		first_node->next = *dst;
		*dst = first_node;
	}
	else
	{
		*dst = first_node;
		first_node->next = NULL;
	}
}

void	pa(t_stack **a, t_stack **b, bool checker)
{
	push_node(a, b);
	if (!checker)
		write(1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b, bool checker)
{
	push_node(b, a);
	if (!checker)
		write(1, "pb\n", 3);
}
