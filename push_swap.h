/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 20:01:41 by dokkim            #+#    #+#             */
/*   Updated: 2021/05/17 22:57:51 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct	s_stack
{
	long long		number;
	struct s_stack	*next;
}				t_stack;

int		ft_split(char **argv, t_stack *stack);

int		ft_arg_check(char **argv);
int		ft_putstr(char *str);
int		ft_duplicate(t_stack *stack, int count);

void	ft_lstclear(t_stack *stack);
t_stack	ft_lstadd_back(t_stack *stack);

void	swap_a(t_stack *stack_a);
void	swap_b(t_stack *stack_b);
void	swap_both(t_stack *stack_a, t_stack *stack_b);

void	push_b(t_stack **stack_a, t_stack **stack_b);
void	push_a(t_stack *stack_a, t_stack *stack_b);

void	reverse_rotate_a(t_stack *stack_a);
void	reverse_rotate_b(t_stack *stack_b);
void	reverse_rotate_both(t_stack *stack_a, t_stack *stack_b);

void	rotate_a(t_stack *stack_a);
void	rotate_b(t_stack *stack_b);
void	rotate_both(t_stack *stack_a, t_stack *stack_b);

#endif
