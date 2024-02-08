/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtu <jtu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:22:55 by jtu               #+#    #+#             */
/*   Updated: 2024/01/31 19:27:36 by jtu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	apply_cmd(t_stack **a, t_stack **b, char *cmd)
{
	if (!ft_strncmp(cmd, "pa\n", 3))
		pa(a, b, true);
	else if (!ft_strncmp(cmd, "pb\n", 3))
		pb(a, b, true);
	else if (!ft_strncmp(cmd, "sa\n", 3))
		sa(a, true);
	else if (!ft_strncmp(cmd, "sb\n", 3))
		sb(b, true);
	else if (!ft_strncmp(cmd, "ss\n", 3))
		ss(a, b, true);
	else if (!ft_strncmp(cmd, "ra\n", 3))
		ra(a, true);
	else if (!ft_strncmp(cmd, "rb\n", 3))
		rb(b, true);
	else if (!ft_strncmp(cmd, "rr\n", 3))
		rr(a, b, true);
	else if (!ft_strncmp(cmd, "rra\n", 4))
		rra(a, true);
	else if (!ft_strncmp(cmd, "rrb\n", 4))
		rrb(b, true);
	else if (!ft_strncmp(cmd, "rrr\n", 4))
		rrr(a, b, true);
	else
		free_var(a);
}

void	parse_cmd(t_stack **a, t_stack **b)
{
	char	*cmd;
	int		len;

	len = stack_len(*a);
	cmd = get_next_line(0);
	while (cmd)
	{
		apply_cmd(a, b, cmd);
		free(cmd);
		cmd = get_next_line(0);
	}
	if (stack_sorted(*a) && stack_len(*a) == len)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc < 2 || (argc >= 2 && !argv[1][0]))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	else if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		init_stack(&a, argv, argc);
	}
	else
		init_stack(&a, argv + 1, argc);
	parse_cmd(&a, &b);
	free_stack(&a);
	free_stack(&b);
}
