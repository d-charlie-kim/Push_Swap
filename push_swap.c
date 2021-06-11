/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 19:54:50 by dokkim            #+#    #+#             */
/*   Updated: 2021/06/10 17:33:15 by dokkim           ###   ########.fr       */
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
	count = parsing(&stack_a, argc, argv);
	if (is_already_sorted(stack_a, count, 'a'))
		ft_done(&stack_a, &stack_b);
	if (count == 4 || count == 5)
		sort_around_five(&stack_a, &stack_b, count);
	else
		chunk_a_to_b(&stack_a, &stack_b, count);
	ft_done(&stack_a, &stack_b);
	return (0);
}
