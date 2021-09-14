/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gariadno <gariadno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 03:05:27 by gariadno          #+#    #+#             */
/*   Updated: 2021/09/14 06:16:52 by gariadno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include "libft.h"

# define NEARGS "Not enough arguments!"
# define MALERR "Malloc error!"
# define NOTNUM "Input not number!"
# define NOTINT "Input not integer!"

typedef struct	s_stack
{
	int				*num;
	struct s_stack	*previous;
	struct s_stack	*next;
}	t_stack;

char	**get_inp(int argc, char **args);

t_stack	*lst_new(int *num);
void	lstadd_back(t_stack **stack, t_stack *new);
void	lstadd_front(t_stack **stack, t_stack *new);
t_stack	*lst_last(t_stack *stack);


int	check_if_args_are_invalid(char **args);


void	free_lst(t_stack **stack);
void	free_mat(char **mat);
void	free_exit(char **mat);

#endif