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

void	ft_swap(t_stack **stack)
{
	t_stack	*second;
	t_stack	*first;

	if ((*stack) != NULL)
	{
		first = *stack;
		second = first->next;
		first->next = second->next;
		second->next = first;
		*stack = second;
	}
}

void	swap_a(t_stack **stack_a)
{
		ft_swap(stack_a);
		ft_putstr("sa");
}

void	swap_b(t_stack **stack_b)
{
		ft_swap(stack_b);
		ft_putstr("sb");
}

void	swap_both(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_a != NULL)
		ft_swap(stack_a);
	if (*stack_b != NULL)
		ft_swap(stack_b);
	if (*stack_a != NULL || *stack_b != NULL)
		ft_putstr("ss");
}