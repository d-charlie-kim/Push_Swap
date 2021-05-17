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

int		lst_to_str(int **str, t_stack *stack, int count)
{
	t_stack	*temp;
	int		i;

	i = 0;
	temp = stack;
	while (i < count)
	{
		(*str)[i] = temp->number;
		i++;
		temp = temp->next;
	}
	return (0);
}

int		partition(int *str, int left, int right)
{
	int	temp;
	int	mark;
	int	low;
	int	high;
	printf("Hello\n");
	low = left + 1;
	high = right;
	mark = str[left];
	while (low < high)
	{
		while (low <= right && mark > str[low])
			low++;
		while (high >= left && mark < str[high])
			high--;
		if (low > high)
		{
			temp = str[low];
			str[low] = str[right];
			str[right] = temp;
		}
	}
	if (low < high)
	{
		temp = str[left];
		str[left] = str[high];
		str[high] = temp;
	}
	printf("Hello\n");
	return (high);
}

void	sorting(int *str, int left, int right)
{
	int mark;

	if (left < right)
	{
		mark = partition(str, left, right);
		sorting(str, left, mark - 1);
		sorting(str, mark + 1, right);
	}
}

int		quick_sort(t_stack *stack, int count)
{
	int		*str;

	str = (int *)malloc(sizeof(int) * count);
	if (!str)
		return (-1);
	if (lst_to_str(&str, stack, count))
		return (-1);
	sorting(str, 0, count - 1);
	int i = 0;
	while (i < count)
	{
		printf("ag : %d ", str[i]);
		printf("\n");
		i++;
	}
	printf ("median : %d\n", str[count / 2]);
	return (0);
}