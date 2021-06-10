/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 01:42:03 by dokkim            #+#    #+#             */
/*   Updated: 2021/06/10 15:53:23 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	if (str[i] != '\n')
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
		ft_error("Error", *stack_a, *stack_b);
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
	char	buffer[4];
	int		size;

	count = parsing(&stack_a, &stack_b, argc, argv);
	size = read(0, buffer, 4);
	while (size > 0)
	{
		if (buffer[0] == 's' || buffer[0] == 'p')
			swap_or_push(&stack_a, &stack_b, buffer);
		else if (buffer[0] == 'r')
			rotate_or_reverse(&stack_a, &stack_b, buffer);
		else
			ft_error("Error", stack_a, stack_b);
		size = read(0, buffer, 4);
	}
	size = ft_lstsize(stack_a);
	if (size != count)
		ft_error("KO", stack_a, stack_b);
	is_sorted(&stack_a, &stack_b, count);
}