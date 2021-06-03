/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_quick.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 20:16:31 by dokkim            #+#    #+#             */
/*   Updated: 2021/05/20 20:16:32 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		find_first_pivot(int *str, int end)
{
	int	i;
	int	j;
	int	count;
	
	i = 0;
	while (i < end)
	{
		count = 0;
		j = 0;
		while (j < end)
		{
			if (str[i] > str[j])
				count++;
			j++;
		}
		if (count == (end / 3) * 2)
			return (str[i]);
		i++;
	}
	return (str[i]);
}
int		find_second_pivot(int *str, int end)
{
	int	i;
	int	j;
	int	count;
	
	i = 0;
	while (i < end)
	{
		count = 0;
		j = 0;
		while (j < end)
		{
			if (str[i] > str[j])
				count++;
			j++;
		}
		if (count == end / 3)
			return (str[i]);
		i++;
	}
	return (str[i]);
}

int		ft_find_pivot(t_stack **stack_a, t_stack **stack_b, int count, int order)
{
	int pivot;
	int *str;

	pivot = 0;
	str = lst_to_str(stack_a, stack_b, count);
	if (order == 1)
		pivot = find_first_pivot(str, count);
	else if (order == 2)
		pivot = find_second_pivot(str, count);
	free(str);
	return (pivot);
}
