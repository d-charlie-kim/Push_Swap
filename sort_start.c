/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 03:25:59 by dokkim            #+#    #+#             */
/*   Updated: 2021/05/20 20:16:44 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort(t_stack **stack_a, t_stack **stack_b, int count, int next)
{
	int		median;
	int		temp;

	if (count > 3)
	{
		printf("count : %d\n", count);
		median = sorting(stack_a, stack_b, count);
		printf("median : %d\n", median);
		ft_median_sort(stack_a, stack_b, median, count);
		next = (count / 2);
		printf("next : %d\n", next);
		count = count - (count / 2);
		ft_sort(stack_a, stack_b, count, next);
	}
	if(count > 1)
	{
		temp = next;
		two_or_three_nor(stack_a, stack_b, count);
		while (temp > 0)
		{
			push_a(stack_a, stack_b);
			temp--;
		}
		ft_sort(stack_a, stack_b, next, 0);
	}
}

void	two_or_three(t_stack **stack_a, t_stack **stack_b, int count)
{
	int	i;

	i = 0;
	if (count == 2)
		two_arg(stack_a, stack_b);
	else if (count == 3)
		three_arg(stack_a, stack_b);
}

void	two_or_three_nor(t_stack **stack_a, t_stack **stack_b, int count)
{
	int	i;

	i = 0;
	if (count == 2)
		two_arg(stack_a, stack_b);
	else if (count == 3)
		three_arg_nor(stack_a, stack_b);
}