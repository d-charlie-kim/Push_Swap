/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 19:54:50 by dokkim            #+#    #+#             */
/*   Updated: 2021/05/23 00:08:26 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		count;

	count = 0;
	stack_a = NULL;
	stack_b = NULL;
	count = parsing(&stack_a, &stack_b, argc, argv);
	if (is_already_sorted(stack_a, count, 'a'))
		ft_done(&stack_a);
	chunk_a_to_b(&stack_a, &stack_b, count);
}
