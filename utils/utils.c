/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 20:54:07 by dokkim            #+#    #+#             */
/*   Updated: 2021/06/11 19:26:08 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		ft_putstr(char *str, int fd)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(fd, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
	return (-1);
}

int		ft_isdigit(char c)
{
	if ((c >= 48 && c <= 57))
		return (1);
	return (0);
}

int		ft_isminus(char c)
{
	if (c == '-')
		return (-1);
	return (1);
}

void	ft_change(int *str, int i, int j)
{
	int	temp;

	temp = str[i];
	str[i] = str[j];
	str[j] = temp;
}

void	ft_find_node(t_stack **temp, int count)
{
	while (count > 0)
	{
		(*temp) = (*temp)->next;
		count--;
	}
}
