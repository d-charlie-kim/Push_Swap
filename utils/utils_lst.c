/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 16:06:29 by dokkim            #+#    #+#             */
/*   Updated: 2021/06/10 15:53:43 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_lstclear(t_stack *stack)
{
	t_stack *temp;
	t_stack *temp2;

	if (!stack)
		return ;
	temp2 = stack;
	while (temp != NULL)
	{
		temp = (temp2)->next;
		if (temp != NULL)
		{
			temp2 = temp->next;
			free(temp);
			temp = temp2;
		}
	}
	if (stack != NULL)
	{
		free(stack);
	}
	stack = NULL;
}

void	ft_lstadd(t_stack **stack, int count)
{
	t_stack *temp;
	int		i;

	i = 1;
	temp = (t_stack *)malloc(sizeof(t_stack));
	if (!temp)
		ft_error("Error", temp, NULL);
	temp->number = 0;
	temp->next = NULL;
	*stack = temp;
	while (i < count)
	{
		temp->next = (t_stack *)malloc(sizeof(t_stack));
		if (!temp)
			ft_error("Error", *stack, NULL);
		temp = temp->next;
		temp->number = 0;
		temp->next = NULL;
		i++;
	}
}

int		*lst_to_str(t_stack **stack_a, t_stack **stack_b, int count)
{
	t_stack	*temp;
	int		*str;
	int		i;

	str = (int *)malloc(sizeof(int) * count);
	if (!str)
		ft_error("Error", *stack_a, *stack_b);
	i = 0;
	temp = *stack_a;
	while (i < count)
	{
		str[i] = temp->number;
		temp = temp->next;
		i++;
	}
	return (str);
}

int		ft_lstsize(t_stack *stack)
{
	int	n;

	n = 0;
	while (stack != NULL)
	{
		stack = stack->next;
		n++;
	}
	return (n);
}
