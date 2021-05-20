/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 03:25:59 by dokkim            #+#    #+#             */
/*   Updated: 2021/05/18 03:26:39 by dokkim           ###   ########.fr       */
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
		{
			temp = str[low];
			str[low] = str[right];
			str[right] = temp;
		}
	}
	if (low > high)
	{
		temp = str[left];
		str[left] = str[high];
		str[high] = temp;
	}
	return (high);
}

void	sorting(int **str, int left, int right)
{
	int mark;

	if (left < right)
	{
		mark = partition(str, left, right);
		sorting(str, left, mark - 1);
		sorting(str, mark + 1, right);
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

void	ft_sort(t_stack **stack_a, t_stack **stack_b, int count)
{
	int	median;

	median = quick_sort(stack_a, stack_b, count);
	printf("median : %d\n", median);
}