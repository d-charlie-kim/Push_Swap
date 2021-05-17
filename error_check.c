/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 21:50:25 by dokkim            #+#    #+#             */
/*   Updated: 2021/05/18 07:07:46 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	duplicate_check(t_stack *stack, int count)
{
	int		i;
	t_stack	*temp;
	t_stack	*temp2;

	i = 0;
	temp = stack;
	while (temp->next != NULL)
	{
		if (temp->number > 2147483647 || (temp->number < -2147483648))
			return (ft_error("Error", stack, NULL));
		temp2 = temp->next;
		while (temp2->next != NULL)
		{
			if (temp->number == temp2->number)
				return (-1);
			temp2 = temp2->next;
		}
		temp = temp->next;
	}
	return (0);
}

int	arg_check(char **argv)
{
	int count;
	int i;
	int j;

	i = 1;
	j = 0;
	count = 0;
	count = valid_check(argv, count, i, j);
	if (arg_range_check(argv, count, i, j) == -1)
		count = -1;
	return (count);
}

int	valid_check(char **argv, int count, int i, int j)
{
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
				return (-1);
			count++;
			while (argv[i][j] >= 48 && argv[i][j] <= 57 && argv[i][j])
				j++;
		}
		i++;
	}
	return (count);
}

int	arg_range_check(char **argv, int count, int i, int j)
{
	int	num;

	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			num = 0;
			while ((argv[i][j] < 48 || argv[i][j] > 57) && argv[i][j])
				j++;
			count++;
			while (argv[i][j] >= 48 && argv[i][j] <= 57 && argv[i][j])
			{
				j++;
				num++;
			}
			if (num >= 11)
				return (-1);
		}
		i++;
	}
	return (0);
}
