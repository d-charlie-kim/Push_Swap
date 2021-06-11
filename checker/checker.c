/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 01:42:03 by dokkim            #+#    #+#             */
/*   Updated: 2021/06/11 18:18:30 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	is_sorted(t_stack **stack_a, t_stack **stack_b, int count)
{
	if (is_already_sorted(*stack_a, count, 'a'))
	{
		ft_lstclear(*stack_a);
		ft_lstclear(*stack_b);
		ft_putstr("OK");
		exit(0);
	}
	else
	{
		ft_lstclear(*stack_a);
		ft_lstclear(*stack_b);
		ft_putstr("KO");
		exit(0);
	}
}

int		ft_strnstr(char *str, char *arr, int n)
{
	int i;

	i = 0;
	while (n > 0 && str[i] && arr[i])
	{
		if (str[i] != arr[i])
			return (0);
		i++;
		n--;
	}
	if (str[i] != '\0' || n > 0)
		return (0);
	return (1);
}

void	swap_or_push(t_stack **stack_a, t_stack **stack_b, char *buffer)
{
	if (ft_strnstr(buffer, "sa", 2))
		ft_swap(stack_a);
	else if (ft_strnstr(buffer, "sb", 2))
		ft_swap(stack_b);
	else if (ft_strnstr(buffer, "ss", 2))
	{
		ft_swap(stack_a);
		ft_swap(stack_b);
	}
	else if (ft_strnstr(buffer, "pa", 2))
		ft_push(stack_b, stack_a);
	else if (ft_strnstr(buffer, "pb", 2))
		ft_push(stack_a, stack_b);
	else
		rotate_or_reverse(stack_a, stack_b, buffer);
}

void	rotate_or_reverse(t_stack **stack_a, t_stack **stack_b, char *buffer)
{
	if (ft_strnstr(buffer, "ra", 2))
		ft_rotate(stack_a);
	else if (ft_strnstr(buffer, "rb", 2))
		ft_rotate(stack_b);
	else if (ft_strnstr(buffer, "rr", 2))
	{
		ft_rotate(stack_a);
		ft_rotate(stack_b);
	}
	else if (ft_strnstr(buffer, "rra", 3))
		reverse_rotate(stack_a);
	else if (ft_strnstr(buffer, "rrb", 3))
		reverse_rotate(stack_b);
	else if (ft_strnstr(buffer, "rrr", 3))
	{
		reverse_rotate(stack_a);
		reverse_rotate(stack_b);
	}
	else
		ft_error("Error", *stack_a, *stack_b);
}

int		main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		count;
	t_gnl	gnl;
	int		temp;

	gnl.backup = NULL;
	gnl.buffer = NULL;
	stack_a = NULL;
	stack_b = NULL;
	count = parsing(&stack_a, &stack_b, argc, argv);
	gnl.size = get_next_line(0, &(gnl.buffer), &(gnl.backup));
	while (gnl.size == 1)
	{
		swap_or_push(&stack_a, &stack_b, gnl.buffer);
		gnl.size = get_next_line(0, &(gnl.buffer), &(gnl.backup));
	}
	if (gnl.size == -1)
		ft_error("Error", stack_a, stack_b);
	temp = ft_lstsize(stack_a);
	if (temp != count)
		ft_error("KO", stack_a, stack_b);
	is_sorted(&stack_a, &stack_b, count);
}
