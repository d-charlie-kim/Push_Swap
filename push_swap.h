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
void	ft_lstnew(t_stack **stack, t_stack **new);

void	ft_parse(char **argv, t_stack **stack_a, int max);
int		ft_split(char *argv, t_stack **stack, int max, int count);

int		ft_putstr(char *str);
int		ft_isdigit(char c);
int		ft_isminus(char c);

int		arg_check(int argc, char **argv);
void	duplicate_check(t_stack *stack);
void	valid_check(char **argv);
int		arg_range_check(char **argv, int count, int num);
void	ft_error(char *str, t_stack *stack_a, t_stack *stack_b);

int		partition(int *str, int left, int right);
void	sorting(int *str, int left, int right);
int		quick_sort(t_stack *stack, int count);
int		lst_to_str(int **str, t_stack *stack, int count);

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

#endif
