/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_few.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gariadno <gariadno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 02:13:44 by gariadno          #+#    #+#             */
/*   Updated: 2021/09/20 20:26:34 by gariadno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	top_is_bigger_than(int top_num, t_stack *stack, int max_cmp)
{
	int	bigger_than;

	if (!stack)
		return (0);
	bigger_than = 0;
	while (stack && max_cmp--)
	{
		if (top_num > stack->num)
			bigger_than++;
		stack = stack->next;
	}
	return (bigger_than);
}

void	sort_three(t_stack **a)
{
	t_stack	*highest;
	t_stack	*tmp;

	highest = *a;
	tmp = (*a)->next;
	while (tmp)
	{
		if (highest->num < tmp->num)
			highest = tmp;
		tmp = tmp->next;
	}
	if (highest == *a)
		rotate(a, RA);
	else if (highest == (*a)->next)
		rev_rotate(a, RRA);
	if ((*a)->num > (*a)->next->num)
		swap(a, SA);
}


void	sort_four(t_stack **a, t_stack **b)
{
	int bigger_than;

	bigger_than = top_is_bigger_than((*a)->num, (*a)->next, 3);
	if (bigger_than == 2)
		swap(a, SA);
	push(b, a, PB);
	sort_three(a);
	bigger_than = top_is_bigger_than((*b)->num, *a, 3);
	push(a, b, PA);
	if (bigger_than && bigger_than < 3)
		sort_few(a, b, ++bigger_than);
	else if (bigger_than == 3)
		rotate(a, RA);
}

void	sort_five(t_stack **a, t_stack **b)
{
	int bigger_than;

	while (1)
	{
		bigger_than = top_is_bigger_than((*a)->num, (*a)->next, 4);
		if (bigger_than == 2 || bigger_than == 3)
			rotate(a, RA);
		else
			break ;
	}
	push(b, a, PB);
	sort_four(a, b);
	bigger_than = top_is_bigger_than((*b)->num, *a, 4);
	push(a, b, PA);
	if (bigger_than && bigger_than < 4)
		sort_few(a, b, ++bigger_than);
	else if (bigger_than == 4)
		rotate(a, RA);
}

void	sort_few(t_stack **a, t_stack **b, int stklen)
{
	if (stklen == 2)
		swap(a, SA);
	if (stklen == 3)
		sort_three(a);
	if (stklen == 4)
		sort_four(a, b);
	if (stklen == 5)
		sort_five(a, b);
}
