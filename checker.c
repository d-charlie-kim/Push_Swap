/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 01:42:03 by dokkim            #+#    #+#             */
/*   Updated: 2021/06/09 01:25:13 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strnstr(char *str, char *arr, int n)
{
	int i;

	i = 0;
	while (n > 1 && str[i] && arr[i])
	{
		printf("iii : %d\n", i);
		if (str[i] != arr[i] || )
			return (0);
		i++;
		n--;
	}
	if ()
		return (0);
	return (1);	
}

int	checker(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		count;

	stack_a = NULL;
	stack_b = NULL;
	arg_check(argc, argv);
	count = arg_count(argv, count);
	ft_lstadd(&stack_a, count);
	ft_parse(argv, &stack_a, count);
	duplicate_check(stack_a);


	char	buffer[4];
	int		size;

	size = read(0, buffer, 4);
	printf("%d\n", size);
	while (size > 0)
	{
		if (ft_strnstr(buffer, "sa", size))
			ft_swap(&stack_a);
		else if (ft_strnstr(buffer, "sb", size))
			ft_swap(&stack_b);
		else if (ft_strnstr(buffer, "ss", size))
		{
			ft_swap(&stack_a);
			ft_swap(&stack_b);
		}
		else if (ft_strnstr(buffer, "pa", size))
			ft_push(&stack_b, &stack_a);
		else if (ft_strnstr(buffer, "pb", size))
			ft_push(&stack_a, &stack_b);
		else if (ft_strnstr(buffer, "ra", size))
			ft_rotate(&stack_a);
		else if (ft_strnstr(buffer, "rb", size))
			ft_rotate(&stack_b);
		else if (ft_strnstr(buffer, "rr", size))
		{
			ft_rotate(&stack_a);
			ft_rotate(&stack_b);
		}
		else if (ft_strnstr(buffer, "rra", size))
			reverse_rotate(&stack_a);
		else if (ft_strnstr(buffer, "rrb", size))
			reverse_rotate(&stack_b);
		else if (ft_strnstr(buffer, "rrr", size))
		{
			reverse_rotate(&stack_a);
			reverse_rotate(&stack_b);
		}

		else
			ft_error("Error", stack_a, stack_b);
		size = read(0, buffer, 4);
	}
	if (is_already_sorted(stack_a, count, 'a'))
	{
		ft_lstclear(stack_a);
		ft_putstr("OK");
		return (0);
	}
	else
	{
		ft_lstclear(stack_a);
		ft_putstr("KO");
		return(0);
	}
}
