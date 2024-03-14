/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtu <jtu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 13:09:38 by jtu               #+#    #+#             */
/*   Updated: 2024/03/14 21:00:49 by jtu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	next_number(int n, t_stack *a)
{
	int		next_n;
	int		next_n_0;
	int		len;
	int		found;
	t_stack	*a_temp;

	a_temp = a;
	len = stack_len(a);
	next_n = INT_MAX;
	next_n_0 = a_temp->value;
	found = 0;
	while (len--)
	{
		if (a_temp->value > n && a_temp->value < next_n)
		{
			next_n = a_temp->value;
			found = 1;
		}
		if (a_temp->value < next_n_0)
			next_n_0 = a_temp->value;
		a_temp = a_temp->next;
	}
	if (found == 1)
		return (next_n);
	return (next_n_0);
}

void	rotate_b(int i, int len, t_moves *best_moves)
{
	if (i <= len - i)
		best_moves->nrb = i;
	else
		best_moves->nrrb = len - i;
}

void	rotate_a(t_stack *a, t_stack *b, t_moves *best_moves)
{
	int		i;
	int		len;
	int		next_n;
	t_stack	*temp;

	i = 0;
	len = stack_len(a);
	temp = a;
	next_n = next_number(b->value, a);
	while (i < len && temp->value != next_n)
	{
		temp = temp->next;
		i++;
	}
	if (i <= len - i)
		best_moves->nra = i;
	else
		best_moves->nrra = len - i;
}

void	replace_rr(t_moves *best_moves)
{
	while (best_moves->nra && best_moves->nrb)
	{
		best_moves->nra--;
		best_moves->nrb--;
		best_moves->nrr++;
	}
	while (best_moves->nrra && best_moves->nrrb)
	{
		best_moves->nrra--;
		best_moves->nrrb--;
		best_moves->nrrr++;
	}
}

void	calculate_best_moves(t_stack **a, t_stack **b, t_values *values,
t_moves *best_moves)
{
	int		len;
	int		i;
	t_stack	*b_temp;
	t_moves	*best_moves_temp;

	len = stack_len(*b);
	best_moves_temp = malloc(sizeof(t_moves));
	if (!best_moves_temp)
		free_everything(a, b, values, best_moves);
	b_temp = *b;
	i = -1;
	while (++i < len)
	{
		init_moves(best_moves_temp);
		rotate_b(i, len, best_moves_temp);
		rotate_a(*a, b_temp, best_moves_temp);
		replace_rr(best_moves_temp);
		best_moves_temp->total = count_bm(best_moves_temp);
		if (best_moves_temp->total < best_moves->total)
			copy_best_moves(best_moves, best_moves_temp);
		if (best_moves->total == 0 || best_moves-> total == 1)
			break ;
		b_temp = b_temp->next;
	}
	free(best_moves_temp);
}
