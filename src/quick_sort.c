/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtu <jtu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 16:09:11 by jtu               #+#    #+#             */
/*   Updated: 2024/03/14 21:00:49 by jtu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_stack	*partition(t_stack *head, t_stack *tail)
{
	int		temp;
	t_stack	*pivot;
	t_stack	*current;

	temp = 0;
	pivot = head;
	current = head;
	while (current && current != tail)
	{
		if (current->value < tail->value)
		{
			pivot = head;
			temp = head->value;
			head->value = current->value;
			current->value = temp;
			head = head->next;
		}
		current = current->next;
	}
	temp = head->value;
	head->value = tail->value;
	tail->value = temp;
	return (pivot);
}

void	quick_sort(t_stack *head, t_stack *tail)
{
	t_stack	*pivot;

	if (head == tail)
		return ;
	pivot = partition(head, tail);
	if (pivot != NULL && pivot->next != NULL)
		quick_sort(pivot->next, tail);
	if (pivot != NULL && head != pivot)
		quick_sort(head, pivot);
}

void	find_values(t_stack *sorted_stack, t_values *values)
{
	int		len;
	int		i;
	t_stack	*temp;

	len = stack_len(sorted_stack);
	values->min = sorted_stack->value;
	temp = sorted_stack;
	i = -1;
	while (++i < len - 1)
	{
		if (i == len / 2 + len % 2 - 1)
			values->median = sorted_stack->value;
		if (i == len - 2)
			values->max2 = sorted_stack->value;
		if (i == len - 3)
			values->max3 = sorted_stack->value;
		if (i == len - 4)
			values->max4 = sorted_stack->value;
		if (i == len - 5)
			values->max5 = sorted_stack->value;
		sorted_stack = sorted_stack->next;
	}
	values->max1 = sorted_stack->value;
	free_stack(&temp);
}
