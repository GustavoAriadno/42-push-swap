/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gariadno <gariadno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 21:04:44 by gariadno          #+#    #+#             */
/*   Updated: 2021/09/12 20:43:31 by gariadno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	free_lst(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack)
		return ;
	while(*stack)
	{
		tmp = (*stack)->next;
		free((*stack)->num);
		free(*stack);
		(*stack) = tmp;
	}
}

void	free_mat(char **matrix)
{
	int	i = 0;

	if (!matrix)
		return ;
	while (matrix[i])
		free(matrix[i++]);
	free(matrix);
}

void	free_exit(char **mat)
{
	free_mat(mat);
	ft_putendl_fd("Error", STDERR_FILENO);
	exit(-1);
}
