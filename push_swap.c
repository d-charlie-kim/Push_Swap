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

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		count;

	stack_a = NULL;
	stack_b = NULL;
	count = arg_check(argc, argv);
	ft_parse(argv, &stack_a, count);
	duplicate_check(stack_a);


//	if (quick_sort(stack_a, count))
//		return (ft_error("Error", stack_a, stack_b));


	// push_b(&stack_a, &stack_b);
	// push_b(&stack_a, &stack_b);
	// rotate_both(&stack_a, &stack_b);
	// reverse_rotate_both(&stack_a, &stack_b);
	// swap_both(&stack_a, &stack_b);

	printf ("\nstack A  //  stack B\n");
	while (stack_a != NULL || stack_b != NULL)
	{
		printf("||  ");
		if (stack_a != NULL)
		{
			printf("%lld", stack_a->number);
			stack_a = stack_a->next;
		}
		else
			printf(" ");
		printf("          ");
		if (stack_b != NULL)
		{
			printf("%lld", stack_b->number);
			stack_b = stack_b->next;
		}
		else
			printf(" ");
		printf("\n");
	}
	return (0);
}