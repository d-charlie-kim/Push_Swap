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

void	ft_lstclear(t_stack *stack);
void	ft_lstadd(t_stack **stack, int count);
int		*lst_to_str(t_stack **stack_a, t_stack **stack_b, int count);
void	ft_find_node(t_stack **temp, int count);

void	ft_done(t_stack **stack);
int		is_already_sorted(t_stack *stack, int count, char c);
void	ft_error(char *str, t_stack *stack_a, t_stack *stack_b);

int		arg_count(char **argv, int count);
void	ft_parse(char **argv, t_stack **stack_a, int max);
int		ft_split(char *argv, t_stack **stack, int max, int count);

int		ft_putstr(char *str);
int		ft_isdigit(char c);
int		ft_isminus(char c);
void	ft_change(int *str, int i, int j);
void	ft_find_node(t_stack **temp, int count);


void	arg_check(int argc, char **argv);
void	duplicate_check(t_stack *stack);
void	valid_check(char **argv);
void	len_check(char **argv, int count);

void	ft_swap(t_stack **stack);
void	swap_a(t_stack **stack_a);
void	swap_b(t_stack **stack_b);
void	swap_both(t_stack **stack_a, t_stack **stack_b);

void	push_a(t_stack **stack_a, t_stack **stack_b);
void	push_b(t_stack **stack_a, t_stack **stack_b);

void	reverse_rotate(t_stack **stack);
void	reverse_rotate_a(t_stack **stack_a);
void	reverse_rotate_b(t_stack **stack_b);
void	reverse_rotate_both(t_stack **stack_a, t_stack **stack_b);

void	ft_rotate(t_stack **stack);
void	rotate_a(t_stack **stack_a);
void	rotate_b(t_stack **stack_b);
void	rotate_both(t_stack **stack_a, t_stack **stack_b);

void	ft_sort(t_stack **stack_a, t_stack **stack_b, int count);
int		is_all_bigger(t_stack **stack_a, t_stack **stack_b, int count, int num);
void	chunk_b_to_a(t_stack **stack_a, t_stack **stack_b, int count);

int		ft_find_pivot(t_stack **stack_a, t_stack **stack_b, int count, int order);
int		find_second_pivot(int *str, int end);
int		find_first_pivot(int *str, int end);

void	two_arg(t_stack **stack_a, t_stack **stack_b);
void	three_arg(t_stack **stack_a, t_stack **stack_b);
void	two_one_three(t_stack **stack_a, t_stack **stack_b);
void	two_three_one(t_stack **stack_a, t_stack **stack_b);
void	one_three_two(t_stack **stack_a, t_stack **stack_b);
void	three_two_one(t_stack **stack_a, t_stack **stack_b);
void	three_one_two(t_stack **stack_a, t_stack **stack_b);

void	two_or_three(t_stack **stack_a, t_stack **stack_b, int count);
void	three_arg_nor(t_stack **stack_a, t_stack **stack_b);
void	two_one_three_nor(t_stack **stack_a, t_stack **stack_b);
void	two_three_one_nor(t_stack **stack_a, t_stack **stack_b);
void	one_three_two_nor(t_stack **stack_a, t_stack **stack_b);
void	three_two_one_nor(t_stack **stack_a, t_stack **stack_b);
void	three_one_two_nor(t_stack **stack_a, t_stack **stack_b);

#endif
