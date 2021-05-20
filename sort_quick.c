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

int		partition(int **string, int left, int right)
{
	int	temp;
	int	low;
	int	high;
	int	*str;
	
	str = *string;
	low = left + 1;
	high = right;
	while (low < high)
	{
		while (low < right && str[left] > str[low])
			low++;
		while (high > left && str[left] < str[high])
			high--;
		if (low < high)
			ft_change(string, low, right);
	}
	if (low > high)
		ft_change(string, left, high);
	return (high);
}

void	sorting(int **str, int left, int right)
{
	int pivot;

	if (left < right)
	{
		pivot = partition(str, left, right);
		sorting(str, left, pivot - 1);
		sorting(str, pivot + 1, right);
	}
}

int		quick_sort(t_stack **stack_a, t_stack **stack_b, int count)
{
	int *str;

	str = (int *)malloc(sizeof(int) * count);
	if (!str)
		ft_error("Malloc Error", *stack_a, *stack_b);
	lst_to_str(&str, stack_a, count);
	sorting(&str, 0, count - 1);
	int i = 0;
	return (str[count / 2]);
}
