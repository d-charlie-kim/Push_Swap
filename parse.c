/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 21:53:57 by dokkim            #+#    #+#             */
/*   Updated: 2021/05/18 07:08:19 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isnum(char c)
{
	if ((c < 48 || c > 57) && c != '-')
		return (1);
	if ((c >= 48 && c <= 57))
		return (2);
	return (1);
}

int	ft_split(char **argv, t_stack **stack, int i, int j)
{
	t_stack	*temp;
	int		minus;

	temp = *stack;
	while (argv[i])
	{
		temp = ft_lstadd(temp);
		if (!(temp))
			return (ft_error("Malloc Error", *stack, NULL));
		j = 0;
		while (argv[i][j])
		{
			minus = 1;
			while ((ft_isnum(argv[i][j]) && argv[i][j]))
				j++;
			if (argv[i][j] == '-')
				minus = -1;
			while ((argv[i][j] >= 48 && argv[i][j] <= 57) && argv[i][j])
				temp->number = (temp->number * 10) + argv[i][j++] - '0';
			temp->number = temp->number * minus;
			temp = temp->next;
		}
		i++;
	}
	return (0);
}
