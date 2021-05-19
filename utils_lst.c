/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 16:06:29 by dokkim            #+#    #+#             */
/*   Updated: 2021/05/17 16:06:31 by dokkim           ###   ########.fr       */
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

t_stack		*ft_lstnew(t_stack **stack, t_stack **new)
{
	t_stack *temp;

	temp = *new;
	temp = (t_stack *)malloc(sizeof(t_stack));
	if (!temp)
		ft_error("Malloc Error", *stack, NULL);
	temp->next = NULL;
	temp->number = 0;
	*new = temp;
	return (temp);
}