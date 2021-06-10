/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 08:25:38 by dokkim            #+#    #+#             */
/*   Updated: 2021/06/10 15:47:03 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	two_one_three(t_stack **stack_a, t_stack **stack_b)
{
	swap_a(stack_a);
}

void	two_three_one(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate_a(stack_a);
}

void	one_three_two(t_stack **stack_a, t_stack **stack_b)
{
	swap_a(stack_a);
	rotate_a(stack_a);
}

void	three_two_one(t_stack **stack_a, t_stack **stack_b)
{
	swap_a(stack_a);
	reverse_rotate_a(stack_a);
}

void	three_one_two(t_stack **stack_a, t_stack **stack_b)
{
	rotate_a(stack_a);
}
