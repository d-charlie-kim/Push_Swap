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
	int		first_chunk;
	int		second_chunk;
	
	temp = count;
	first_chunk = 0;
	second_chunk = 0;
	if (count > 3)
	{
		first = ft_find_pivot(stack_a, stack_b, count, 1);
		second = ft_find_pivot(stack_a, stack_b, count, 2);
		// printf("count : %d\n", count);
		// printf("first pivot : %d\n", first);
		// printf("second pivot : %d\n", second);
		if (is_already_sorted(*stack_a, count))
			return ;
		while (temp > 0)
		{
			if (((*stack_a)->number) >= second)
			{
				rotate_a(stack_a);
				first_chunk++;
			}
			else if (second > ((*stack_a)->number) && ((*stack_a)->number) >= first)
			{
				push_b(stack_a, stack_b);
				second_chunk++;
			}
			else if (first > ((*stack_a)->number))
			{
				push_b(stack_a, stack_b);
				rotate_b(stack_b);
			}
			temp--;
		}
		temp = first_chunk + 1;
		while (--temp > 0)
			reverse_rotate_a(stack_a);
		ft_sort(stack_a, stack_b, first_chunk);
	}
	if (count < 4)
		two_or_three_nor(stack_a, stack_b, count);
	temp = second_chunk;
	if (count > 3 && temp > 0)
	{
		while (temp > 0)
		{
			push_a(stack_a, stack_b);
			temp--;
		}
		ft_sort(stack_a, stack_b, second_chunk);
	}
	temp = count - first_chunk - second_chunk;
	if (count > 3 && temp > 0)
	{
		while (temp > 0)
		{
			push_a(stack_a, stack_b);
			temp--;
		}
		ft_sort(stack_a, stack_b, count - first_chunk - second_chunk);
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
	int		i;
	int		num;
	t_stack	*temp;

	i = 0;
	num = 3;
	temp = *stack_a;
	while (num > 0 && temp != NULL)
	{
		temp = temp->next;
		num--;
	}
	if (temp == NULL)
		return(two_or_three(stack_a, stack_b, count));
	if (count == 2)
		two_arg(stack_a, stack_b);
	else if (count == 3)
		three_arg_nor(stack_a, stack_b);
}