/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 20:14:12 by dokkim            #+#    #+#             */
/*   Updated: 2021/05/20 20:17:41 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_push(t_stack **stack_from, t_stack **stack_to)
{
	t_stack *temp;

	if ((*stack_from) != NULL)
	{
		temp = (*stack_from)->next;
		(*stack_from)->next = (*stack_to);
		(*stack_to) = (*stack_from);
		(*stack_from) = temp;
	}
}

void	push_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;

	ft_push(stack_b, stack_a);
	ft_putstr("pa");
}

void	push_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;

	ft_push(stack_a, stack_b);
	ft_putstr("pb");
}
