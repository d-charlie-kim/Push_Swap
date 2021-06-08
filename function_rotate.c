/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 20:14:06 by dokkim            #+#    #+#             */
/*   Updated: 2021/05/20 20:17:20 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*first;
	t_stack *second;

		first = *stack;
		second = first->next;
		last = *stack;
		while (last->next)
			last = last->next;
		first->next = last->next;
		last->next = first;
		*stack = second;
}

void	rotate_a(t_stack **stack_a)
{
	if (((*stack_a) != NULL) && ((*stack_a)->next != NULL))
	{
		ft_rotate(stack_a);
		ft_putstr("ra");
	}
}

void	rotate_b(t_stack **stack_b)
{
	if (((*stack_b) != NULL) && ((*stack_b)->next != NULL))
	{
		ft_rotate(stack_b);
		ft_putstr("rb");
	}
}

void	rotate_both(t_stack **stack_a, t_stack **stack_b)
{
	if (((*stack_a) != NULL) && ((*stack_a)->next != NULL))
	{
		if (((*stack_b) != NULL) && ((*stack_b)->next != NULL))
		{
			ft_rotate(stack_a);
			ft_rotate(stack_b);
			ft_putstr("rr");
		}
		else
			rotate_a(stack_a);
	}
	else if (((*stack_b) != NULL) && ((*stack_b)->next != NULL))
		rotate_b(stack_b);
}
