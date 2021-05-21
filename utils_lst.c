/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 16:06:29 by dokkim            #+#    #+#             */
/*   Updated: 2021/05/20 18:07:57 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		ft_error("Malloc Error", temp, NULL);
	temp->number = 0;
	temp->next = NULL;
	*stack = temp;
	while (i < count)
	{
		temp->next = (t_stack *)malloc(sizeof(t_stack));
		if (!temp)
			ft_error("Malloc Error", *stack, NULL);
		temp = temp->next;
		temp->number = 0;
		temp->next = NULL;
		i++;
	}
}

void	lst_to_str(int *str, t_stack **stack, int count)
{
	t_stack	*temp;
	int		i;

	i = 0;
	temp = *stack;
	while (i < count)
	{
		str[i] = temp->number;
		temp = temp->next;
		i++;
	}
}