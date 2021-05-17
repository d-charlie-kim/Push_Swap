/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 19:54:50 by dokkim            #+#    #+#             */
/*   Updated: 2021/05/17 22:55:16 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int     ft_sort(t_stack *stack_a, t_stack *stack_b)
// {

// }

int	main(int argc, char **argv)
{
	t_stack *stack_a;
	t_stack *stack_b;
	int count;

	if (argc < 2)
		return (ft_putstr("Error"));
	count = ft_arg_check(argv);
	if (count <= 0)
		return (ft_putstr("Error"));
	stack_a = (t_stack *)malloc(sizeof(t_stack));
	if (!(stack_a))
		return (ft_putstr("Memory Error"));
	stack_a->next = NULL;
	stack_b = NULL;
	if (ft_split(argv, stack_a))
		return (ft_putstr("Error"));
	if (ft_duplicate(stack_a, count))
	{
		ft_lstclear(stack_a);
		return (ft_putstr("Error"));
	}
	push_b(&stack_a, &stack_b);
	push_b(&stack_a, &stack_b);
	printf ("stack a  //  stack b\n");
	while (stack_a != NULL || stack_b != NULL)
	{
		printf("||  %lld    //  %lld  ||\n", stack_a->number, stack_b->number);
		if (stack_a != NULL)
			stack_a = stack_a->next;
		if (stack_b != NULL)
			stack_b = stack_b->next;
	}



	// if (ft_sort(stack_a, stack_b))
	// {
	//     ft_lstclear(stack_a);
	//     ft_lstclear(stack_b);
	//     return (ft_putstr("Error"));
	// }
	return (0);
}