/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 20:14:01 by dokkim            #+#    #+#             */
/*   Updated: 2021/06/11 18:12:09 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_swap(t_stack **stack)
{
	t_stack	*second;
	t_stack	*first;

	if ((*stack) != NULL && (*stack)->next != NULL)
	{
		first = *stack;
		second = first->next;
		first->next = second->next;
		second->next = first;
		*stack = second;
	}
}

void	swap_a(t_stack **stack_a, t_stack **stack_b)
{
	ft_swap(stack_a);
	if (((*stack_b) != NULL) && ((*stack_b)->next != NULL))
	{
		if (((*stack_b)->number) < (((*stack_b)->next)->number))
		{
			ft_swap(stack_b);
			ft_putstr("ss");
			return ;
		}
		else
		{
			ft_putstr("sa");
			return ;
		}
	}
	else
		ft_putstr("sa");
}

void	swap_b(t_stack **stack_a, t_stack **stack_b)
{
	ft_swap(stack_b);
	if (((*stack_a) != NULL) && ((*stack_a)->next != NULL))
	{
		if (((*stack_a)->number) > (((*stack_a)->next)->number))
		{
			ft_swap(stack_a);
			ft_putstr("ss");
			return ;
		}
		else
		{
			ft_putstr("sb");
			return ;
		}
	}
	else
		ft_putstr("sb");
}

void	swap_both(t_stack **stack_a, t_stack **stack_b)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
	ft_putstr("ss");
}
