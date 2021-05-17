/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 20:14:01 by dokkim            #+#    #+#             */
/*   Updated: 2021/05/17 22:55:59 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack *stack_a)
{
	t_stack	*temp;

	if (stack_a != NULL)
	{
		temp = stack_a->next;
		stack_a->next = temp->next;
		temp->next = stack_a;
		stack_a = temp;
		ft_putstr("sa");
	}
}

void	swap_b(t_stack *stack_b)
{
	t_stack	*temp;

	if (stack_b != NULL)
	{
		temp = stack_b->next;
		stack_b->next = temp->next;
		temp->next = stack_b;
		stack_b = temp;
		ft_putstr("sb");
	}
}

void	swap_both(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*temp;

	if (stack_a != NULL)
	{
		temp = stack_a->next;
		stack_a->next = temp->next;
		temp->next = stack_a;
		stack_a = temp;
	}
	if (stack_b != NULL)
	{
		temp = stack_b->next;
		stack_b->next = temp->next;
		temp->next = stack_b;
		stack_b = temp;
	}
	if (stack_a != NULL || stack_b != NULL)
		ft_putstr("ss");
}
