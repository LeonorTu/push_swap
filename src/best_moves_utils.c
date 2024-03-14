/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_moves_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtu <jtu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 19:02:14 by jtu               #+#    #+#             */
/*   Updated: 2024/03/14 21:00:21 by jtu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	init_moves(t_moves *moves)
{
	moves->nra = 0;
	moves->nrb = 0;
	moves->nrr = 0;
	moves->nrra = 0;
	moves->nrrb = 0;
	moves->nrrr = 0;
	moves->total = INT_MAX;
}

int	count_bm(t_moves *best_moves)
{
	int	total;

	total = best_moves->nra + best_moves->nrb + best_moves->nrr
		+ best_moves->nrra + best_moves->nrrb + best_moves->nrrr;
	best_moves->total = total;
	return (total);
}

void	copy_best_moves(t_moves *best_moves, t_moves *best_moves_temp)
{
	best_moves->nra = best_moves_temp->nra;
	best_moves->nrb = best_moves_temp->nrb;
	best_moves->nrr = best_moves_temp->nrr;
	best_moves->nrra = best_moves_temp->nrra;
	best_moves->nrrb = best_moves_temp->nrrb;
	best_moves->nrrr = best_moves_temp->nrrr;
	best_moves->total = best_moves_temp->total;
}

void	apply_best_moves(t_stack **a, t_stack **b, t_moves *best_moves)
{
	while (best_moves->nrr--)
		rr(a, b, false);
	while (best_moves->nrrr--)
		rrr(a, b, false);
	while (best_moves->nrrb--)
		rrb(b, false);
	while (best_moves->nrb--)
		rb(b, false);
	while (best_moves->nra--)
		ra(a, false);
	while (best_moves->nrra--)
		rra(a, false);
	pa(a, b, false);
}
