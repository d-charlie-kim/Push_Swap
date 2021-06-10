/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_two_or_three.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 15:35:40 by dokkim            #+#    #+#             */
/*   Updated: 2021/06/10 15:35:41 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	two_or_three(t_stack **stack_a, t_stack **stack_b, int count)
{
	int		i;
	int		num;
	t_stack	*temp;

	i = 0;
	num = 3;
	temp = *stack_a;
	while (num > 0 && temp != NULL)
	{
		temp = temp->next;
		num--;
	}
	if (count == 2)
		two_arg(stack_a, stack_b);
	if (count == 3 && temp == NULL)
		return (three_arg(stack_a, stack_b));
	else if (count == 3)
		three_arg_nor(stack_a, stack_b);
}

void	two_arg(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *first;
	t_stack *second;

	first = *stack_a;
	second = (*stack_a)->next;
	if (first->number > second->number)
		swap_a(stack_a);
}

void	three_arg_nor(t_stack **stack_a, t_stack **stack_b)
{
	long long	first;
	long long	second;
	long long	third;

	first = (*stack_a)->number;
	second = ((*stack_a)->next)->number;
	third = (((*stack_a)->next)->next)->number;
	if (first < second && second < third)
		return ;
	else if (first < third && third < second)
		one_three_two_nor(stack_a, stack_b);
	else if (second < first && first < third)
		two_one_three_nor(stack_a, stack_b);
	else if (second < third && third < first)
		three_one_two_nor(stack_a, stack_b);
	else if (third < second && second < first)
		three_two_one_nor(stack_a, stack_b);
	else if (third < first && first < second)
		two_three_one_nor(stack_a, stack_b);
}

void	three_arg(t_stack **stack_a, t_stack **stack_b)
{
	long long	first;
	long long	second;
	long long	third;

	first = (*stack_a)->number;
	second = ((*stack_a)->next)->number;
	third = (((*stack_a)->next)->next)->number;
	if (first < second && second < third)
		return ;
	else if (first < third && third < second)
		one_three_two(stack_a, stack_b);
	else if (second < first && first < third)
		two_one_three(stack_a, stack_b);
	else if (second < third && third < first)
		three_one_two(stack_a, stack_b);
	else if (third < second && second < first)
		three_two_one(stack_a, stack_b);
	else if (third < first && first < second)
		two_three_one(stack_a, stack_b);
}
