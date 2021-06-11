/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_nor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 08:25:38 by dokkim            #+#    #+#             */
/*   Updated: 2021/06/10 16:04:01 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	two_one_three_nor(t_stack **stack_a, t_stack **stack_b)
{
	swap_a(stack_a, stack_b);
}

void	two_three_one_nor(t_stack **stack_a, t_stack **stack_b)
{
	push_b(stack_a, stack_b);
	swap_a(stack_a, stack_b);
	push_a(stack_a, stack_b);
	swap_a(stack_a, stack_b);
}

void	one_three_two_nor(t_stack **stack_a, t_stack **stack_b)
{
	push_b(stack_a, stack_b);
	swap_a(stack_a, stack_b);
	push_a(stack_a, stack_b);
}

void	three_two_one_nor(t_stack **stack_a, t_stack **stack_b)
{
	swap_a(stack_a, stack_b);
	push_b(stack_a, stack_b);
	swap_a(stack_a, stack_b);
	push_a(stack_a, stack_b);
	swap_a(stack_a, stack_b);
}

void	three_one_two_nor(t_stack **stack_a, t_stack **stack_b)
{
	swap_a(stack_a, stack_b);
	push_b(stack_a, stack_b);
	swap_a(stack_a, stack_b);
	push_a(stack_a, stack_b);
}
