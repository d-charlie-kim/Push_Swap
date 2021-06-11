/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 16:17:49 by dokkim            #+#    #+#             */
/*   Updated: 2021/06/10 16:18:16 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	reverse_together(t_stack **stack_a, t_stack **stack_b,
												int num1, int num2)
{
	while (num1 > 0 && num2 > 0)
	{
		reverse_rotate_both(stack_a, stack_b);
		num1--;
		num2--;
	}
	while (num1 > 0)
	{
		reverse_rotate_a(stack_a);
		num1--;
	}
	while (num2 > 0)
	{
		reverse_rotate_b(stack_b);
		num2--;
	}
}
