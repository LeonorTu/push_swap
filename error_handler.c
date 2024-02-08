/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtu <jtu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 20:05:40 by jtu               #+#    #+#             */
/*   Updated: 2024/02/01 15:16:39 by jtu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	invalid_argv(char *str)
{
	if (*str == '+' || *str == '-')
	{
		str++;
		if (!*str)
			return (1);
	}
	if (*str < '0' || *str > '9')
		return (1);
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (1);
		str++;
	}
	return (0);
}

int	duplicated_argv(t_stack *stack, int n)
{
	while (stack)
	{
		if (stack->value == n)
			return (1);
		stack = stack->next;
	}
	return (0);
}
