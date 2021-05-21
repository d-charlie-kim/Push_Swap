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

void	median_to_a(t_stack **stack_a, t_stack **stack_b, int median, int count)
{

}

void	median_to_b(t_stack **stack_a, t_stack **stack_b, int median, int count)
{
	int	i;

	i = 0;
	while(i < count / 2)
	{
		if (((*stack_a)->number) < median)
			push_b(stack_a, stack_b);
		else
		{
			while (((*stack_a)->number) >= median)
			{
				if ((*stack_b) && (*stack_b)->next && (*stack_b)->number < ((*stack_b)->next)->number)
					rotate_both(stack_a, stack_b);
				else
					rotate_a(stack_a);
			}
			push_b(stack_a, stack_b);
		}
		i++;
	}
}

void	ft_median_sort(t_stack **stack_a, t_stack **stack_b, int median, int count)
{
	int	i;

	i = 0;
	median_to_b(stack_a, stack_b, median, count);
}

void	ft_sort(t_stack **stack_a, t_stack **stack_b, int count)
{
	int		median;

	while (count > 3)
	{
		median = get_median(stack_a, stack_b, count);
		printf("median : %d\n", median);
		printf("count : %d\n", count);
		ft_median_sort(stack_a, stack_b, median, count);
		if (count % 2 == 1)
			count++;
		count = (count / 2);
	}
}
