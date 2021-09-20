/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gariadno <gariadno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 03:05:27 by gariadno          #+#    #+#             */
/*   Updated: 2021/09/20 20:27:11 by gariadno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include "libft.h"

# define SA "sa"
# define SB "sb"
# define PA "pa"
# define PB "pb"
# define RA "ra"
# define RB "rb"
# define RRA "rra"
# define RRB "rrb"

typedef struct s_stack
{
	int				num;
	struct s_stack	*previous;
	struct s_stack	*next;
}	t_stack;

t_stack	*lst_last(t_stack *stack);
t_stack	*lst_new(int num);
void	lstadd_back(t_stack **stack, t_stack *new);
int		lst_len(t_stack *stack);

int		are_args_invalid(char **args);
int		is_sorted(t_stack *stack);
int		is_lownb_sorted(t_stack *stack);

void	start_sort(t_stack **a, t_stack **b, int stklen);
void	sort_few(t_stack **a, t_stack **b, int stklen);

void	swap(t_stack **stack, char *opstr);
void	push(t_stack **dst, t_stack **src, char *opstr);
void	rotate(t_stack **stack, char *opstr);
void	rev_rotate(t_stack **stack, char *opstr);

void	free_lst(t_stack *stack);
void	free_mat(char **matrix);
void	free_exit(char **mat);

#endif