/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhabacuc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 18:35:28 by lhabacuc          #+#    #+#             */
/*   Updated: 2024/08/16 18:35:30 by lhabacuc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

void	radix_sort(t_stack **a, t_stack **b)
{
	int	max_bits;
	int	i;
	int	j;
	int	size;

	size = stack_size(*a);
	max_bits = find_max_bits(*a);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if ((((*a)->index >> i) & 1) == 1)
				ra(a);
			else
				pb(a, b);
			j++;
		}
		while (*b)
			pa(a, b);
		i++;
	}
}

void	four_sort(t_stack **a, t_stack **b)
{
	put_min_to_top(a);
	pb(a, b);
	three_sort(a);
	pa(a, b);
	if ((*a)->data > (*a)->next->data)
		sa(a);
	while (*b)
		pa(a, b);
}

void	five_sort(t_stack **a, t_stack **b)
{
	put_min_to_top(a);
	pb(a, b);
	put_min_to_top(a);
	pb(a, b);
	three_sort(a);
	pa(a, b);
	pa(a, b);
}

int	find_max_bits(t_stack *stack)
{
	int	max;
	int	bits;

	max = 0;
	bits = 0;
	while (stack)
	{
		if (stack->index > max)
			max = stack->index;
		stack = stack->next;
	}
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

void	indexing(t_stack *stack)
{
	t_stack		*current;
	t_stack		*compare;
	int			index;

	current = stack;
	while (current)
	{
		index = 0;
		compare = stack;
		while (compare)
		{
			if (current->data > compare->data)
				index++;
			compare = compare->next;
		}
		current->index = index;
		current = current->next;
	}
}
