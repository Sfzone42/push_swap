/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate03.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhabacuc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 18:14:20 by lhabacuc          #+#    #+#             */
/*   Updated: 2024/08/16 18:14:22 by lhabacuc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

int	validate_limit(char **av, int p)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (ft_atoi(av[i]) == MAX_I)
		{
			if (p)
				exit_error(av);
			exit_error(NULL);
		}
		i++;
	}
	return (0);
}

int	check_duplicates(char **av, int p, int i, int j)
{
	while (av[i])
	{
		if (!is_number(av[i]) || !valor_null(av[i]))
		{
			if (p)
				exit_error(av);
			exit_error(NULL);
		}
		j = i + 1;
		while (av[j])
		{
			if (ft_atoi(av[i]) == ft_atoi(av[j]))
			{
				if (p)
					exit_error(av);
				exit_error(NULL);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	find_min(t_stack *a)
{
	t_stack	*tmp;
	int		pos_min;
	int		min;

	tmp = a;
	min = small(a);
	pos_min = 0;
	while (tmp)
	{
		if (tmp->data == min)
			break ;
		pos_min++;
		tmp = tmp->next;
	}
	return (pos_min);
}

void	put_min_to_top(t_stack **a)
{
	int	min_pos;

	min_pos = find_min(*a);
	if (min_pos < stack_size(*a) / 2)
	{
		while (min_pos)
		{
			ra(a);
			min_pos--;
		}
	}
	else if (min_pos >= stack_size(*a) / 2)
	{
		while (min_pos != stack_size(*a))
		{
			rra(a);
			min_pos++;
		}
	}
}
