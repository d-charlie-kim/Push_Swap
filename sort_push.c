/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 20:14:12 by dokkim            #+#    #+#             */
/*   Updated: 2021/05/17 22:58:39 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;

	if ((*stack_b) != NULL)
	{
		temp = (*stack_b)->next;
		(*stack_b)->next = (*stack_a);
		(*stack_a) = (*stack_b);
		(*stack_b) = temp;
		ft_putstr("pa");
	}
}

void	push_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;

	if ((*stack_a) != NULL)
	{
		temp = (*stack_a)->next;
		(*stack_a)->next = (*stack_b);
		(*stack_b) = (*stack_a);
		(*stack_a) = temp;
		ft_putstr("pb");
	}
}
