/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_quick.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 20:16:31 by dokkim            #+#    #+#             */
/*   Updated: 2021/05/20 20:16:32 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		sorting(t_stack **stack_a, t_stack **stack_b, int count)
{
	int	*str;
	int	median;

	str = (int *)malloc(sizeof(int) * count);
	if (!str)
		ft_error("Malloc Error", *stack_a, *stack_b);
	lst_to_str(str, stack_a, count);
	median = get_median(str, count);
	free(str);
	return (median);
}

int		get_median(int *str, int end)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	while (i < end)
	{
		count = 0;
		j = 0;
		while (j < end)
		{
			if (str[i] > str[j])
				count++;
			j++;
		}
		if (count == end / 2)
			return (str[i]);
		i++;
	}
	return (str[i]);
}

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
