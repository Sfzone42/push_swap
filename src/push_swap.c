/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhabacuc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 18:13:38 by lhabacuc          #+#    #+#             */
/*   Updated: 2024/08/16 18:13:40 by lhabacuc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

void	init_stacks(char **av, t_stack **a)
{
	int	len;

	*a = NULL;
	len = 0;
	while (av[len])
		len++;
	len--;
	while (len >= 0)
	{
		push(a, ft_atoi(av[len]));
		len--;
	}
	indexing(*a);
}

void	sort_stack_logic(t_stack **a, t_stack **b, int i)
{
	if (is_sorted(*a) == 0)
	{
		free_stack(*a);
		return ;
	}
	if (i == 1)
	{
		free_stack(*a);
		return ;
	}
	if (i == 2)
		two_sort(a);
	else if (i == 3)
		three_sort(a);
	else if (i == 4)
		four_sort(a, b);
	else if (i == 5)
		five_sort(a, b);
	else if (i > 5)
		radix_sort(a, b);
	free_stack(*b);
	free_stack(*a);
}

void	initialize_sorting(char **av, int i)
{
	t_stack		*a;
	t_stack		*b;

	b = NULL;
	init_stacks(av, &a);
	while (av[i])
		i++;
	sort_stack_logic(&a, &b, i);
}

int	process_arguments(char **av, int p)
{
	check_duplicates(av, p, 0, 0);
	validate_limit(av, p);
	initialize_sorting(av, 0);
	return (0);
}

int	main(int arc, char **av)
{
	char		**avg;

	if (arc == 2)
	{
		if (check_string(av[1]) == 0)
			return (0);
		if (!valor_null(av[1]) || is_space(av[1]))
			exit_error(NULL);
		avg = ft_split(av[1], 0, 0, 0);
		process_arguments(avg, 1);
		free_matrix(avg);
	}
	else if (arc > 2)
		process_arguments(av + 1, 0);
	return (0);
}
