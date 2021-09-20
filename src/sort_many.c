/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_many.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gariadno <gariadno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 02:14:01 by gariadno          #+#    #+#             */
/*   Updated: 2021/09/20 02:14:02 by gariadno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	lower_numbers(t_stack **radix, t_stack *origin)
{
	t_stack	*aux;
	t_stack	*first_el;
	int		bigger_than;

	first_el = origin;
	while (origin)
	{
		aux = first_el;
		bigger_than = 0;
		while (aux)
		{
			if (origin->num > aux->num)
				bigger_than++;
			aux = aux->next;
		}
		aux = lst_new(bigger_than);
		if (!aux)
			break ;
		lstadd_back(radix, aux);
		origin = origin->next;
	}
	if (origin)
		return (1);
	return (0);
}

void	radix(t_stack **a, t_stack **b)
{
	int	bit_place;
	int	stack_len;

	bit_place = 0b00000001;
	while (!is_sorted(*a))
	{
		stack_len = lst_len(*a);
		while (stack_len)
		{
			if (((*a)->num & bit_place))
				rotate(a, RA);
			else
				push(b, a, PB);
			if (is_lownb_sorted(*a))
				break ;
			stack_len--;
		}
		while (*b)
			push(a, b, PA);
		bit_place <<= 1;
	}
}

void	sort_many(t_stack **a, t_stack **b)
{
	t_stack	*radix_stack;

	radix_stack = NULL;
	if (lower_numbers(&radix_stack, *a))
	{
		free_lst(*a);
		free_lst(radix_stack);
		ft_putendl_fd("Error", STDERR_FILENO);
		exit(-1);
	}
	radix(&radix_stack, b);
	free_lst(radix_stack);
}
