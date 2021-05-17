/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 20:14:06 by dokkim            #+#    #+#             */
/*   Updated: 2021/05/17 21:45:31 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_stack *stack_a)
{
	t_stack	*last;
	t_stack	*temp;

	if (stack_a != NULL)
	{
		temp = stack_a->next;
		last = stack_a->next;
		while (last->next != NULL)
			last = last->next;
		last->next = stack_a;
		stack_a->next = NULL;
		stack_a = temp;
		ft_putstr("ra");
	}
}

void	rotate_b(t_stack *stack_b)
{
	t_stack	*last;
	t_stack	*temp;

	if (stack_b != NULL)
	{
		temp = stack_b->next;
		last = stack_b->next;
		while (last->next != NULL)
			last = last->next;
		last->next = stack_b;
		stack_b->next = NULL;
		stack_b = temp;
		ft_putstr("rb");
	}
}

void	rotate_both(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*last;
	t_stack	*temp;

	if (stack_a != NULL)
	{
		temp = stack_a->next;
		last = stack_a->next;
		while (last->next != NULL)
			last = last->next;
		last->next = stack_a;
		stack_a->next = NULL;
		stack_a = temp;
	}
	if (stack_b != NULL)
	{
		temp = stack_b->next;
		last = stack_b->next;
		while (last->next != NULL)
			last = last->next;
		last->next = stack_b;
		stack_b->next = NULL;
		stack_b = temp;
	}
	if (stack_a != NULL || stack_b != NULL)
		ft_putstr("rr");
}
