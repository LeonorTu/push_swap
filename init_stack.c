/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtu <jtu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:02:07 by jtu               #+#    #+#             */
/*   Updated: 2024/02/01 15:38:46 by jtu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atoi_long(const char *str)
{
	long	value;
	int		sign;

	value = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str ++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= 48 && *str <= 57)
	{
		if (value > LONG_MAX / 10)
			return (LONG_MAX);
		value *= 10;
		if (value > LONG_MAX - (*str - '0'))
			return (LONG_MAX);
		value += *str - '0';
		str++;
	}
	return (sign * value);
}

void	init_stack(t_stack **stack, char **argv, int argc)
{
	int		i;
	long	n;

	i = 0;
	if (!argv[i])
		write(2, "Error\n", 6);
	while (argv[i])
	{
		if (invalid_argv(argv[i]))
			free_var(stack);
		n = ft_atoi_long(argv[i]);
		if (n < INT_MIN || n > INT_MAX)
			free_var(stack);
		if (duplicated_argv(*stack, n))
			free_var(stack);
		add_node(stack, n);
		i++;
	}
	if (argc == 2)
		free_array(argv);
}
