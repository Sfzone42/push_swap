/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_val.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhabacuc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 18:13:00 by lhabacuc          #+#    #+#             */
/*   Updated: 2024/08/16 18:13:02 by lhabacuc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

void	is_digit_validate(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == ' ')
			i++;
		if (((s[i] == '-' || s[i] == '+')
				&& (s[i + 1] == '-' || s[i + 1] == '+')) && s[i] != ' ')
			exit_error(NULL);
		if (s[i] == ' ')
			i++;
		i++;
	}
}

void	dup_signal(const char *str)
{
	while (*str != '\0')
	{
		if (*str == '+' && *(str + 1) == '-')
			exit_error(NULL);
		if (*str == '-' && *(str + 1) == '-')
			exit_error(NULL);
		if (*str == ' ' && *(str + 1) == '-' && *(str - 1) == ' ')
			exit_error(NULL);
		if (*str == ' ' && *(str + 1) == '+' && *(str - 1) == ' ')
			exit_error(NULL);
		if (*str == '-' && *(str + 1) == '+' && *(str + 2) == '-')
			exit_error(NULL);
		if (*str == '=' && *(str + 1) == '+' && *(str + 2) == '-')
			exit_error(NULL);
		if (*str == '=')
			exit_error(NULL);
		str++;
	}
}

int	check_string(const char *str)
{
	int	i;

	i = 0;
	is_digit_validate(str);
	dup_signal(str);
	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '-' || str[i] == '+')
			i++;
		if (!(str[i] >= '0' && str[i] <= '9')
			&& (str[i] != '+' || str[i] != '-'))
			exit_error(NULL);
		if ((str[i] >= '0' && str[i] <= '9'))
		{
			if (str[i + 1] == '+' || str[i + 1] == '-')
				exit_error(NULL);
		}
		i++;
	}
	return (1);
}

int	ft_atoi(const char *str)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
		if (!(*str >= '0' && *str <= '9'))
			exit_error(NULL);
	}
	while (*str >= '0' && *str <= '9')
	{
		if (result > (MAX_I - (*str - '0')) / 10)
			return (MAX_I);
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}

char	**ft_split(char *str, int i, int j, int l)
{
	char		**split;
	int			k;

	while (str[l] != '\0')
		l++;
	split = malloc(sizeof(char *) * (l + 1));
	if (!split || !str)
		return (NULL);
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	while (str[i])
	{
		k = 0;
		split[j] = malloc(sizeof(char) * (l + 1));
		if (!split[j])
			return (NULL);
		while (str[i] != ' ' && str[i] != '\t' && str[i] != '\0')
			split[j][k++] = str[i++];
		split[j++][k] = '\0';
		while (str[i] == ' ' || str[i] == '\t')
			i++;
	}
	split[j] = NULL;
	return (split);
}
