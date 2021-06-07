/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_reverse_rotate.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 20:14:06 by dokkim            #+#    #+#             */
/*   Updated: 2021/05/20 20:17:01 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*first;
	t_stack *last_before;

		first = *stack;
		last = first->next;
		last_before = first;
		while (last->next != NULL)
		{
			last_before = last_before->next;
			last = last->next;
		}
		last_before->next = NULL;
		last->next = first;
		*stack = last;
}

void	reverse_rotate_a(t_stack **stack_a)
{
	if (((*stack_a) != NULL) && ((*stack_a)->next != NULL))
	{
		reverse_rotate(stack_a);
		ft_putstr("rra");
	}
}

void	reverse_rotate_b(t_stack **stack_b)
{
	if (((*stack_b) != NULL) && ((*stack_b)->next != NULL))
	{
		reverse_rotate(stack_b);
		ft_putstr("rrb");
	}
}

void	reverse_rotate_both(t_stack **stack_a, t_stack **stack_b)
{
	if (((*stack_a) != NULL) && ((*stack_a)->next != NULL))
	{
		if (((*stack_b) != NULL) && ((*stack_b)->next != NULL))
		{
			reverse_rotate(stack_a);
			reverse_rotate(stack_b);
			ft_putstr("rrr");
		}
		reverse_rotate_a(stack_a);
	}
	else if (((*stack_b) != NULL) && ((*stack_b)->next != NULL))
		reverse_rotate_b(stack_b);
}
