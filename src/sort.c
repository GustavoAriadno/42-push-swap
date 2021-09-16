
#include "push_swap.h"

void	sort_three(t_stack **a)
{
	t_stack *highest;
	t_stack *tmp;

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

void	sort_few(t_stack **a, t_stack **b, int stklen)
{
	if (stklen == 2)
		swap(a, SA);
	if (stklen == 3)
		sort_three(a);
	// if (stklen == 4)
	// 	sort_four(a, b);
	// if (stklen == 5)
	// 	sort_five(a, b);
	(void)b;
}
void	start_sort(t_stack **a, t_stack **b)
{
	int	stklen;

	stklen = lst_len(*a);
	if (stklen <= 5)
		sort_few(a, b, stklen);
	// else
	// 	sort_many(a, b);
}
