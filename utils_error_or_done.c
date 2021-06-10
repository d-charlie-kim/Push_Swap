/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_error_or_done.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 17:51:33 by dokkim            #+#    #+#             */
/*   Updated: 2021/06/10 16:03:17 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_done(t_stack **stack)
{
	ft_lstclear(*stack);
	exit(0);
}

int		sorted_a_stack(t_stack *stack, int count)
{
	t_stack	*first;
	t_stack	*second;

	first = stack;
	second = stack->next;
	while (count > 1 && (first->number) < (second->number))
	{
		first = second;
		second = first->next;
		count--;
	}
	return (count);
}

int		sorted_b_stack(t_stack *stack, int count)
{
	t_stack	*first;
	t_stack	*second;

	first = stack;
	second = stack->next;
	while (count-- > 1 && (first->number) > (second->number))
	{
		first = second;
		second = first->next;
		count--;
	}
	return (count);
}

int		is_already_sorted(t_stack *stack, int count, char c)
{
	t_stack	*first;
	t_stack	*second;

	first = stack;
	second = stack->next;
	if (c == 'a')
		count = sorted_a_stack(stack, count);
	else if (c == 'b')
		count = sorted_b_stack(stack, count);
	if (count == 1)
		return (1);
	return (0);
}

void	ft_error(char *str, t_stack *stack_a, t_stack *stack_b)
{
	ft_lstclear(stack_a);
	ft_lstclear(stack_b);
	ft_putstr(str);
	exit(-1);
}
