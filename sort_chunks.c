/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_chunks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 03:25:59 by dokkim            #+#    #+#             */
/*   Updated: 2021/06/10 17:08:08 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_chunks	cycle_a_to_b(t_stack **stack_a, t_stack **stack_b,
										int count, t_chunks chunks)
{
	chunks.first_chunk = 0;
	chunks.second_chunk = 0;
	chunks.last_chunk = 0;
	while (count > 0)
	{
		if (((*stack_a)->number) >= chunks.second)
		{
			rotate_a(stack_a);
			chunks.first_chunk++;
		}
		else if (chunks.second > ((*stack_a)->number)
					&& ((*stack_a)->number) > chunks.first)
		{
			push_b(stack_a, stack_b);
			rotate_b(stack_b);
			chunks.second_chunk++;
		}
		else if (chunks.first >= ((*stack_a)->number))
		{
			push_b(stack_a, stack_b);
			chunks.last_chunk++;
		}
		count--;
	}
	return (chunks);
}

void		chunk_a_to_b(t_stack **stack_a, t_stack **stack_b, int count)
{
	t_chunks	chunks;

	if (count > 3)
	{
		chunks.first = ft_find_pivot(stack_a, stack_b, count, 1);
		chunks.second = ft_find_pivot(stack_a, stack_b, count, 2);
		if (is_already_sorted(*stack_a, count, 'a'))
			return ;
		chunks = cycle_a_to_b(stack_a, stack_b, count, chunks);
		reverse_together(stack_a, stack_b,
			chunks.first_chunk, chunks.second_chunk);
		chunk_a_to_b(stack_a, stack_b, chunks.first_chunk);
		chunk_b_to_a(stack_a, stack_b, chunks.second_chunk);
		chunk_b_to_a(stack_a, stack_b, chunks.last_chunk);
	}
	if (count < 4)
	{
		two_or_three(stack_a, stack_b, count);
		return ;
	}
}

t_chunks	cycle_b_to_a(t_stack **stack_a, t_stack **stack_b,
										int count, t_chunks chunks)
{
	chunks.first_chunk = 0;
	chunks.second_chunk = 0;
	chunks.last_chunk = 0;
	while (count > 0)
	{
		if (((*stack_b)->number) <= chunks.first)
		{
			rotate_b(stack_b);
			chunks.last_chunk++;
		}
		else if (chunks.second > ((*stack_b)->number)
						&& ((*stack_b)->number) > chunks.first)
		{
			push_a(stack_a, stack_b);
			rotate_a(stack_a);
			chunks.second_chunk++;
		}
		else if (chunks.second <= ((*stack_b)->number))
		{
			push_a(stack_a, stack_b);
			chunks.first_chunk++;
		}
		count--;
	}
	return (chunks);
}

void		chunk_b_to_a(t_stack **stack_a, t_stack **stack_b, int count)
{
	int			temp;
	t_chunks	chunks;

	if (count > 3)
	{
		chunks.first = ft_find_pivot(stack_b, stack_a, count, 1);
		chunks.second = ft_find_pivot(stack_b, stack_a, count, 2);
		if (is_already_sorted(*stack_a, count, 'b'))
			return ;
		chunks = cycle_b_to_a(stack_a, stack_b, count, chunks);
		chunk_a_to_b(stack_a, stack_b, chunks.first_chunk);
		reverse_together(stack_a, stack_b,
				chunks.second_chunk, chunks.last_chunk);
		chunk_a_to_b(stack_a, stack_b, chunks.second_chunk);
		chunk_b_to_a(stack_a, stack_b, chunks.last_chunk);
	}
	if (count < 4)
	{
		temp = count + 1;
		while (--temp > 0)
			push_a(stack_a, stack_b);
		two_or_three(stack_a, stack_b, count);
		return ;
	}
}
