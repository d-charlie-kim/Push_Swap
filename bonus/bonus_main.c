/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 19:32:45 by dokkim            #+#    #+#             */
/*   Updated: 2021/06/11 19:32:57 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		count;
	t_gnl	gnl;
	int		temp;

	gnl.buffer = NULL;
	stack_a = NULL;
	stack_b = NULL;
	count = parsing(&stack_a, argc, argv);
	gnl.size = get_next_line(0, &(gnl.buffer));
	while (gnl.size == 1)
	{
		swap_or_push(&stack_a, &stack_b, gnl.buffer);
		gnl.size = get_next_line(0, &(gnl.buffer));
	}
	if (gnl.size == -1)
		ft_error("Error", stack_a, stack_b);
	temp = ft_lstsize(stack_a);
	if (temp != count)
		ft_error("KO", stack_a, stack_b);
	is_sorted(&stack_a, &stack_b, count);
}
