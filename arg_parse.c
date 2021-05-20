/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 21:53:57 by dokkim            #+#    #+#             */
/*   Updated: 2021/05/20 20:18:38 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_parse(char **argv, t_stack **stack_a, int max)
{
	int		i;
	int		count;

	i = 1;
	count = 0;
	while (argv[i])
	{
		count = ft_split(argv[i], stack_a, max, count);
		i++;
	}
}

int		ft_split(char *argv, t_stack **stack, int max, int count)
{
	int		i;
	int		minus;
	t_stack	*temp;

	i = 0;
	temp = *stack;
	while (argv[i] && count < max)
	{
		while (argv[i] == ' ' && argv[i])
			i++;
		minus = ft_isminus(argv[i]);
		if ((argv[i] == '-' || argv[i] == '+') && argv[i])
			i++;
		while (ft_isdigit(argv[i]) && argv[i])
		{
			temp->number = (temp->number * 10) + argv[i] - '0';
			i++;
		}
		count++;
		temp->number = temp->number * minus;
		temp = temp->next;
	}
	return (count);
}
