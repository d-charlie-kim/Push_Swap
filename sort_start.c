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

	while (count > 3)
	{
		median = sorting(stack_a, stack_b, count);
								printf("median : %d\n", median);
								printf("count : %d\n", count);
		ft_median_sort(stack_a, stack_b, median, count);
		if (count % 2 == 1)
			count++;
		count = (count / 2);
	}
	two_or_three(stack_a, stack_b, count);
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