/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtu <jtu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 16:25:59 by jtu               #+#    #+#             */
/*   Updated: 2024/03/14 21:00:49 by jtu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sort_stack(t_stack **a, t_stack **b)
{
	if (!stack_sorted(*a))
	{
		if (stack_len(*a) == 2)
			sa(a, false);
		else if (stack_len(*a) == 3)
			sort_three(a);
		else if (stack_len(*a) == 4)
			sort_four(a, b);
		else if (stack_len(*a) == 5)
			sort_five(a, b);
		else
			push_swap(a, b);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	**temp;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	else if (argc == 2)
	{
		temp = ft_split(argv[1], ' ');
		init_stack(&a, temp, argc);
	}
	else
		init_stack(&a, argv + 1, argc);
	sort_stack(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
