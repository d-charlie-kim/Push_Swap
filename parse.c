/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 21:53:57 by dokkim            #+#    #+#             */
/*   Updated: 2021/05/17 23:09:23 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_split(char **argv, t_stack *stack)
{
	t_stack	*temp;
	int		i;
	int		j;
	int		k;
	int		minus;

	i = 1;
	temp = stack;
	temp->number = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			minus = 1;
			while (argv[i][j] == ' ' && argv[i][j])
				j++;
			if ((argv[i][j] == '-' || argv[i][j] == '+') && argv[i][j])
			{
				if (argv[i][j] == '-')
					minus = -1;
				j++;
			}
			k = 0;
			while (argv[i][j] >= 48 && argv[i][j] <= 57 && argv[i][j])
			{
				temp->number = (temp->number * 10) + argv[i][j] - '0';
				k++;
				j++;
			}
			if (k >= 11 || temp->number > 2147483648
							|| (temp->number == 2147483648 && minus == 1))
			{
				ft_lstclear(stack);
				return (-1);
			}
			temp->number = temp->number * minus;
			temp->next = (t_stack *)malloc(sizeof(t_stack));
			if (!(temp->next))
			{
				ft_lstclear(stack);
				return (-1);
			}
			temp = temp->next;
			temp->number = 0;
			temp->next = NULL;
		}
		i++;
	}
	return (0);
}
