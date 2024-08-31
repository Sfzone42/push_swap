/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhabacuc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 18:35:04 by lhabacuc          #+#    #+#             */
/*   Updated: 2024/08/16 18:35:07 by lhabacuc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

void	three_sort(t_stack **a)
{
	if ((*a)->data > (*a)->next->data && (*a)->next->data
		< (*a)->next->next->data && (*a)->data < (*a)->next->next->data)
		sa(a);
	else if ((*a)->data > (*a)->next->data
		&& (*a)->next->data > (*a)->next->next->data)
	{
		sa(a);
		rra(a);
	}
	else if ((*a)->data > (*a)->next->data
		&& (*a)->next->data < (*a)->next->next->data)
		ra(a);
	else if ((*a)->data < (*a)->next->data && (*a)->next->data
		> (*a)->next->next->data && (*a)->data > (*a)->next->next->data)
		rra(a);
	else if ((*a)->data < (*a)->next->data
		&& (*a)->next->data > (*a)->next->next->data)
	{
		sa(a);
		ra(a);
	}
}

void	two_sort(t_stack **a)
{
	if (!a || !*a)
		return ;
	if (stack_size(*a) == 2)
	{
		if ((*a)->data > (*a)->next->data)
			sa(a);
	}
	else if (stack_size(*a) == 3)
		three_sort(a);
}

int	is_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->data > stack->next->data)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int	small(t_stack *a)
{
	t_stack	*tmp;
	int		min;

	tmp = a;
	min = tmp->data;
	while (tmp)
	{
		if (tmp->data < min)
			min = tmp->data;
		tmp = tmp->next;
	}
	return (min);
}
