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

int		arg_check(int argc, char **argv)
{
	int	count;
	int	num;

	count = 0;
	if (argc >= 2)
	{
		valid_check(argv);
		count = arg_range_check(argv, count, num);
		if (count >= 1)
			return (count);
	}
	ft_error("ARG Error", NULL, NULL);
	exit(-1);
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

int		arg_range_check(char **argv, int count, int num)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			num = 0;
			while ((argv[i][j] < 48 || argv[i][j] > 57) && argv[i][j])
				j++;
			if (argv[i][j])
				count++;
			while (argv[i][j] >= 48 && argv[i][j] <= 57 && argv[i][j])
			{
				j++;
				num++;
			}
			if (num >= 11)
				ft_error("Overflow Error", NULL, NULL);
		}
		i++;
	}
	return (count);
}

void	ft_error(char *str, t_stack *stack_a, t_stack *stack_b)
{
	ft_lstclear(stack_a);
	ft_lstclear(stack_b);
	ft_putstr(str);
	exit(-1);
}
