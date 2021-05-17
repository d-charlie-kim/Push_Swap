/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_reverse_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 20:14:06 by dokkim            #+#    #+#             */
/*   Updated: 2021/05/17 22:59:47 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_a(t_stack *stack_a)
{
	t_stack	*last;
	t_stack	*temp;

	if (stack_a != NULL)
	{
		temp = stack_a;
		last = stack_a->next;
		while (last->next != NULL)
		{
			temp = temp->next;
			last = last->next;
		}
		temp->next = NULL;
		last->next = stack_a;
		stack_a = last;
		ft_putstr("rra");
	}
}

void	reverse_rotate_b(t_stack *stack_b)
{
	t_stack	*last;
	t_stack	*temp;

	if (stack_b != NULL)
	{
		temp = stack_b;
		last = stack_b->next;
		while (last->next != NULL)
		{
			temp = temp->next;
			last = last->next;
		}
		temp->next = NULL;
		last->next = stack_b;
		stack_b = last;
		ft_putstr("rrb");
	}
}

void	reverse_rotate_both(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*last;
	t_stack	*temp;

	if (stack_a != NULL)
	{
		temp = stack_a;
		last = stack_a->next;
		while (last->next != NULL)
		{
			temp = temp->next;
			last = last->next;
		}
		temp->next = NULL;
		last->next = stack_a;
		stack_a = last;
	}
	if (stack_b != NULL)
	{
		temp = stack_b;
		last = stack_b->next;
		while (last->next != NULL)
		{
			temp = temp->next;
			last = last->next;
		}
		temp->next = NULL;
		last->next = stack_b;
		stack_b = last;
	}
	if (stack_a != NULL || stack_b != NULL)
		ft_putstr("rrr");
}
