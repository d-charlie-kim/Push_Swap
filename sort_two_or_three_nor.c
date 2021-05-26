/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 08:25:38 by dokkim            #+#    #+#             */
/*   Updated: 2021/05/25 08:25:41 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	two_one_three_nor(t_stack **stack_a, t_stack **stack_b)
{
	swap_a(stack_a);
}

void	two_three_one_nor(t_stack **stack_a, t_stack **stack_b)
{
	push_b(stack_a, stack_b);
	swap_a(stack_a);
	push_a(stack_a, stack_b);
	swap_a(stack_a);
}

void	one_three_two_nor(t_stack **stack_a, t_stack **stack_b)
{
	push_b(stack_a, stack_b);
	swap_a(stack_a);
	push_a(stack_a, stack_b);
}

void	three_two_one_nor(t_stack **stack_a, t_stack **stack_b)
{
	swap_a(stack_a);
	push_b(stack_a, stack_b);
	swap_a(stack_a);
	push_a(stack_a, stack_b);
	swap_a(stack_a);
}

void	three_one_two_nor(t_stack **stack_a, t_stack **stack_b)
{
	swap_a(stack_a);
	push_b(stack_a, stack_b);
	swap_a(stack_a);
	push_a(stack_a, stack_b);
}

void	three_arg_nor(t_stack **stack_a, t_stack **stack_b)
{
	long long	first;
	long long	second;
	long long	third;

	first = (*stack_a)->number;
	second = ((*stack_a)->next)->number;
	third = (((*stack_a)->next)->next)->number;
	if (first < second && second < third)
		return ;
	else if (first < third && third < second)
		one_three_two_nor(stack_a, stack_b);
	else if (second < first && first < third)
		two_one_three_nor(stack_a, stack_b);
	else if (second < third && third < first)
		three_one_two_nor(stack_a, stack_b);
	else if (third < second && second < first)
		three_two_one_nor(stack_a, stack_b);
	else if (third < first && first < second)
		two_three_one_nor(stack_a, stack_b);
}