/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhabacuc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 18:14:03 by lhabacuc          #+#    #+#             */
/*   Updated: 2024/08/16 18:14:05 by lhabacuc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	free_stack(t_stack *stack)
{
	t_stack	*tmp;

	while (stack)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}

void	exit_error(char **matriz)
{
	free_matrix(matriz);
	ft_putstr("Error\n");
	exit(0);
}

void	free_matrix(char **matriz)
{
	int	i;

	i = 0;
	if (matriz != NULL)
	{
		while (matriz[i])
		{
			free(matriz[i]);
			i++;
		}
		free(matriz);
	}
}

void	push(t_stack **a, int value)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	new_node->data = value;
	new_node->next = *a;
	*a = new_node;
}

int	stack_size(t_stack *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}
