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

void	ft_sort(t_stack **stack_a, t_stack **stack_b, int count)
{
	int		median;
	int		i;

	i = 0;
	median = quick_sort(stack_a, stack_b, count);
	printf("median : %d\n", median);
	while (i < count)
	{	
		if (((*stack_a)->number) > median)
			push_b(stack_a, stack_b);
		else
		{
			if ((*stack_a)->number > ((*stack_a)->next)->number)
			{
				if ((*stack_b) && (*stack_b)->next && (*stack_b)->number > ((*stack_b)->next)->number)
					swap_both(stack_a, stack_b);
				else
					swap_a(stack_a);
			}
			else
			{
				if ((*stack_b) && (*stack_b)->next && (*stack_b)->number < ((*stack_b)->next)->number)
					rotate_both(stack_a, stack_b);
				else
					rotate_a(stack_a);
			}
		}
		i++;
	}
	while ()
}
