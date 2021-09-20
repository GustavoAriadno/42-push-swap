/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gariadno <gariadno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 02:14:58 by gariadno          #+#    #+#             */
/*   Updated: 2021/09/20 02:14:59 by gariadno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	there_are_duplicates(char **args)
{
	int	i;
	int	j;
	int	cmplen;

	i = -1;
	while (args[++i])
	{
		j = i;
		cmplen = ft_strlen(args[i]) + 1;
		while (args[++j])
			if (ft_strncmp(args[i], args[j], cmplen) == 0)
				return (1);
	}
	return (0);
}

int	args_are_invalid(char **args)
{
	int	i;

	i = -1;
	while (args[++i])
		if (!ft_strisnum(args[i])
			|| ft_strlen(args[i]) > 11
			|| (ft_strlen(args[i]) == 11 && args[i][0] != '-'))
			return (1);
	return (there_are_duplicates(args));
}

int	is_sorted(t_stack *stack)
{
	while (stack)
	{
		if (stack->next)
			if (stack->num > stack->next->num)
				return (0);
		stack = stack->next;
	}
	return (1);
}

int	is_lownb_sorted(t_stack *stack)
{
	while (stack)
	{
		if (stack->next)
			if (stack->next->num - stack->num != 1)
				return (0);
		stack = stack->next;
	}
	return (1);
}
