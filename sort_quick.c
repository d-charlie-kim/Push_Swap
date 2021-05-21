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

int		get_median(t_stack **stack_a, t_stack **stack_b, int count)
{
	int	*str;
	int	median;

	str = (int *)malloc(sizeof(int) * count);
	if (!str)
		ft_error("Malloc Error", *stack_a, *stack_b);
	lst_to_str(str, stack_a, count);
	median = sorting(str, count);
	free(str);
	return (median);
}

int		sorting(int *str, int end)
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
		if (count == end / 2)
			return (str[i]);
		i++;
	}
	return (str[i]);
}
