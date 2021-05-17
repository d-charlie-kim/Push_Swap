/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 21:50:25 by dokkim            #+#    #+#             */
/*   Updated: 2021/05/17 21:50:26 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_duplicate(t_stack *stack, int count)
{
	int i;
	t_stack *temp;
	t_stack *temp2;

	i = 0;
	temp = stack;
	while (temp->next != NULL)
	{
		temp2 = temp->next;
		while (temp2->next != NULL)
		{
			if (temp->number == temp2->number)
				return (1);
			temp2 = temp2->next;
		}
		temp = temp->next;
	}
	return (0);
}

int	ft_arg_check(char **argv)
{
	int count;
	int i;
	int j;

	i = 1;
	count = 0;
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