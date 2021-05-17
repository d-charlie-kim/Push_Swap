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

	temp2 = stack;
	if (!temp2)
		return ;
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

t_stack		*ft_lstadd(t_stack *stack)
{
	t_stack *temp;

	temp = stack;
	temp = (t_stack *)malloc(sizeof(t_stack));
	if (!temp)
		return (NULL);
	temp->next = NULL;
	temp->number = 0;
	return (temp);
}