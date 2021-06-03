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
	int		first;
	int		second;
	int		temp;
	int		next_chunk;
	t_stack	*stack;

	stack = *stack_a;
	temp = count;
	next_chunk = 0;
	if (count > 3)
	{
		first = ft_find_pivot(stack_a, stack_b, count, 1);
		second = ft_find_pivot(stack_a, stack_b, count, 2);
		printf("first pivot : %d\n", first);
		printf("second pivot : %d\n", second);
		if (is_already_sorted(*stack_a, count))
			return ;
		while (temp > 0)
		{
			if ((stack->number) >= first)
				rotate_a(stack_a);
			else if (first > (stack->number) && (stack->number) >= second)
			{
				push_b(stack_a, stack_b);
				next_chunk++;
			}
			else if (second > (stack->number))
			{
				push_b(stack_a, stack_b);
				rotate_b(stack_b);
			}
			temp--;
			stack = stack->next;
		}
		//ft_sort(stack_a, stack_b, count / 3);
	}
}

// int		chunk_a_to_b(t_stack **stack_a, int first, int second, int count)
// {
// 	t_stack	*temp;

// 	temp = *stack_a;
// }

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