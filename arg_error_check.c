/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_error_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 21:50:25 by dokkim            #+#    #+#             */
/*   Updated: 2021/05/20 20:18:35 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	arg_check(int argc, char **argv)
{
	int count;

	count = 0;
	if (argc >= 2)
	{
		valid_check(argv);
		len_check(argv, count);
	}
	else
		ft_error("ARG Error", NULL, NULL);
}

void	duplicate_check(t_stack *stack)
{
	t_stack	*first;
	t_stack	*second;

	first = stack;
	while (first != NULL)
	{
		if (first->number > 2147483647 || (first->number < -2147483648))
			ft_error("Overflow Error", stack, NULL);
		second = first->next;
		while (second != NULL)
		{
			if (first->number == second->number)
				ft_error("Duplicate Error", stack, NULL);
			second = second->next;
		}
		first = first->next;
	}
}

void	valid_check(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			while (argv[i][j] == ' ' && argv[i][j])
				j++;
			if ((argv[i][j] == '-' || argv[i][j] == '+') && argv[i][j])
				j++;
			if ((argv[i][j] < 48 || argv[i][j] > 57) && argv[i][j])
				ft_error("ARG Error", NULL, NULL);
			while (argv[i][j] >= 48 && argv[i][j] <= 57 && argv[i][j])
				j++;
		}
		i++;
	}
}

void	len_check(char **argv, int count)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			count = 0;
			while (argv[i][j] == ' ' && argv[i][j])
				j++;
			if ((argv[i][j] == '-' || argv[i][j] == '+') && argv[i][j])
				j++;
			while (argv[i][j] == '0' && argv[i][j])
				j++;
			while (argv[i][j] >= 48 && argv[i][j] <= 57 && argv[i][j])
			{
				j++;
				count++;
			}
			if (count >= 11)
				ft_error("ARG Error", NULL, NULL);
		}
		i++;
	}
}