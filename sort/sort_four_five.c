/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four_five.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 13:04:44 by dokkim            #+#    #+#             */
/*   Updated: 2021/06/11 18:11:53 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		find_median(int *str, int count)
{
	int		i;
	int		j;
	int		num;

	i = 0;
	num = 0;
	while (i < count)
	{
		j = 0;
		num = 0;
		while (j < count)
		{
			if (str[j] > str[i])
				num++;
			j++;
		}
		if (num == 2)
			return (str[i]);
		i++;
	}
	return (0);
}

void	sort_around_five(t_stack **stack_a, t_stack **stack_b, int count)
{
	int		pivot;
	int		*str;
	int		i;

	i = 0;
	str = lst_to_str(stack_a, stack_b, count);
	pivot = find_median(str, count);
	free(str);
	while (i < count)
	{
		if ((*stack_a)->number < pivot)
			push_b(stack_a, stack_b);
		else
			rotate_a(stack_a);
		i++;
	}
	two_or_three(stack_a, stack_b, 3);
	sort_four_or_five(stack_a, stack_b, count - 3);
}

void	sort_four_or_five(t_stack **stack_a, t_stack **stack_b, int count)
{
	if (count == 1)
		push_a(stack_a, stack_b);
	else if (count == 2)
	{
		if ((*stack_b)->number > ((*stack_b)->next)->number)
		{
			push_a(stack_a, stack_b);
			push_a(stack_a, stack_b);
		}
		else
		{
			swap_b(stack_a, stack_b);
			push_a(stack_a, stack_b);
			push_a(stack_a, stack_b);
		}
	}
}
