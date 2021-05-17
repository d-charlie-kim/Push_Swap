/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 20:54:07 by dokkim            #+#    #+#             */
/*   Updated: 2021/05/17 22:55:36 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
	return (-1);
}

int	ft_error(char *str, t_stack *stack_a, t_stack *stack_b)
{
	ft_lstclear(stack_a);
	ft_lstclear(stack_b);
	ft_putstr(str);
	return (-1);
}