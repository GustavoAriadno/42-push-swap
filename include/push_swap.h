/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gariadno <gariadno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 03:05:27 by gariadno          #+#    #+#             */
/*   Updated: 2021/09/17 00:16:30 by gariadno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include "libft.h"

# define NEARGS "Not enough arguments!"
# define MALERR "Malloc error!"
# define NOTNUM "Input not number!"
# define NOTINT "Input not integer!"

# define SA "sa"
# define SB "sb"
# define SS "ss"
# define PA "pa"
# define PB "pb"
# define RA "ra"
# define RB "rb"
# define RR "rr"
# define RRA "rra"
# define RRB "rrb"
# define RRR "rrr"

typedef struct	s_stack
{
	int				num;
	struct s_stack	*previous;
	struct s_stack	*next;
}	t_stack;

char	**get_inp(int argc, char **args);

t_stack	*lst_new(int num);
void	lstadd_back(t_stack **stack, t_stack *new);
t_stack	*lst_last(t_stack *stack);
int		lst_len(t_stack *stack);


int		args_are_invalid(char **args);
int		is_sorted(t_stack *stack);

void	start_sort(t_stack **a, t_stack **b);


void	swap(t_stack **stack, char *opstr);
void	push(t_stack **a, t_stack **b, char *opstr);
void	rotate(t_stack **stack, char *opstr);
void	rev_rotate(t_stack **stack, char *opstr);


void	free_lst(t_stack *stack);
void	free_mat(char **matrix);
void	free_exit(char **mat);

#endif