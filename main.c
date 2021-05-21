/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 19:54:50 by dokkim            #+#    #+#             */
/*   Updated: 2021/05/20 20:17:59 by dokkim           ###   ########.fr       */
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
	arg_check(argc, argv);
	count = arg_count(argv, count);
	ft_lstadd(&stack_a, count);
	ft_parse(argv, &stack_a, count);
	duplicate_check(stack_a);
	if (is_already_sorted(stack_a))
		ft_done(&stack_a);
	ft_sort(&stack_a, &stack_b, count);



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
}
