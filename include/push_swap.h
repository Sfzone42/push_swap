/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhabacuc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 22:06:45 by lhabacuc          #+#    #+#             */
/*   Updated: 2024/08/16 22:06:47 by lhabacuc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# define MAX_I 2147483647

typedef struct s_stack
{
	struct s_stack	*next;
	int				data;
	int				index;
}	t_stack;

/* Funções de inicialização*/
void	initialize_sorting(char **av, int i);
void	push(t_stack **a, int value);
void	sort_stack_logic(t_stack **a, t_stack **b, int i);
void	indexing(t_stack *stack);

/* Funções de validação*/
int		is_number(char *str);
int		valor_null(char *p);
int		stack_size(t_stack *stack);
int		check_duplicates(char **av, int p, int i, int j);
int		validate_limit(char **av, int p);
int		check_string(const char *str);
int		is_sorted(t_stack *stack);
int		is_space(char *c);
void	dup_signal(const char *str);
void	is_digit_validate(const char *s);

/* Funções auxiliares*/
int		ft_atoi(const char *str);
int		ft_strcmp(char *s1, char *s2);
void	ft_putstr(char *str);
void	exit_error(char **matriz);
void	free_matrix(char **matriz);
void	free_stack(t_stack *stack);
char	**ft_split(char *str, int i, int j, int l);

/* Funções de operações com stacks*/
void	sa(t_stack **a);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rra(t_stack **a);

/* Funções de ordenação*/
void	two_sort(t_stack **a);
void	three_sort(t_stack **a);
void	four_sort(t_stack **a, t_stack **b);
void	five_sort(t_stack **a, t_stack **b);
void	radix_sort(t_stack **a, t_stack **b);

/* Funções de auxílio para ordenação*/
int		small(t_stack *a);
int		find_min(t_stack *a);
int		find_max_bits(t_stack *stack);
void	put_min_to_top(t_stack **a);

/* Funções do programa principal*/
int		process_arguments(char **av, int p);

#endif
