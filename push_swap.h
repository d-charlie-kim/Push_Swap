/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 20:01:41 by dokkim            #+#    #+#             */
/*   Updated: 2021/06/11 18:49:39 by dokkim           ###   ########.fr       */
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

typedef struct	s_chunks
{
	int				first_chunk;
	int				second_chunk;
	int				last_chunk;
	int				first;
	int				second;
}				t_chunks;

typedef struct	s_gnl
{
	char			*buffer;
	int				size;
	char			*backup;
}				t_gnl;

int				arg_count(char **argv, int count);

int				parsing(t_stack **stack_a, int argc, char **argv);
void			ft_parse(char **argv, t_stack **stack_a, int max);
int				ft_split(char *argv, t_stack **stack, int max, int count);

void			arg_check(int argc, char **argv);
void			duplicate_check(t_stack *stack);
void			valid_check(char **argv);
void			len_check(char **argv, int count);

void			ft_lstclear(t_stack *stack);
void			ft_lstadd(t_stack **stack, int count);
int				*lst_to_str(t_stack **stack_a, t_stack **stack_b, int count);
int				ft_lstsize(t_stack *stack);

void			ft_done(t_stack **stack_a, t_stack **stack_b);
int				sorted_b_stack(t_stack *stack, int count);
int				sorted_a_stack(t_stack *stack, int count);
int				is_already_sorted(t_stack *stack, int count, char c);
void			ft_error(char *str, t_stack *stack_a, t_stack *stack_b);

int				ft_putstr(char *str);
int				ft_isdigit(char c);
int				ft_isminus(char c);
void			ft_change(int *str, int i, int j);
void			ft_find_node(t_stack **temp, int count);

void			ft_swap(t_stack **stack);
void			swap_a(t_stack **stack_a, t_stack **stack_b);
void			swap_b(t_stack **stack_a, t_stack **stack_b);
void			swap_both(t_stack **stack_a, t_stack **stack_b);

void			ft_push(t_stack **stack_from, t_stack **stack_to);
void			push_a(t_stack **stack_a, t_stack **stack_b);
void			push_b(t_stack **stack_a, t_stack **stack_b);

void			reverse_rotate(t_stack **stack);
void			reverse_rotate_a(t_stack **stack_a);
void			reverse_rotate_b(t_stack **stack_b);
void			reverse_rotate_both(t_stack **stack_a, t_stack **stack_b);

void			ft_rotate(t_stack **stack);
void			rotate_a(t_stack **stack_a);
void			rotate_b(t_stack **stack_b);
void			rotate_both(t_stack **stack_a, t_stack **stack_b);

void			chunk_a_to_b(t_stack **stack_a, t_stack **stack_b, int count);
void			chunk_b_to_a(t_stack **stack_a, t_stack **stack_b, int count);
t_chunks	cycle_a_to_b(t_stack **stack_a, t_stack **stack_b,
										int count, t_chunks chunks);
t_chunks	cycle_b_to_a(t_stack **stack_a, t_stack **stack_b,
										int count, t_chunks chunks);

void	reverse_together(t_stack **stack_a, t_stack **stack_b,
												int num1, int num2);

int				ft_find_pivot(t_stack **stack_a, t_stack **stack_b,
										int count, int order);
int				find_second_pivot(int *str, int end);
int				find_first_pivot(int *str, int end);

void			two_arg(t_stack **stack_a, t_stack **stack_b);
void			three_arg(t_stack **stack_a, t_stack **stack_b);
void			two_one_three(t_stack **stack_a, t_stack **stack_b);
void			two_three_one(t_stack **stack_a);
void			one_three_two(t_stack **stack_a, t_stack **stack_b);
void			three_two_one(t_stack **stack_a, t_stack **stack_b);
void			three_one_two(t_stack **stack_a);

void			two_or_three(t_stack **stack_a, t_stack **stack_b, int count);
void			three_arg_nor(t_stack **stack_a, t_stack **stack_b);
void			two_one_three_nor(t_stack **stack_a, t_stack **stack_b);
void			two_three_one_nor(t_stack **stack_a, t_stack **stack_b);
void			one_three_two_nor(t_stack **stack_a, t_stack **stack_b);
void			three_two_one_nor(t_stack **stack_a, t_stack **stack_b);
void			three_one_two_nor(t_stack **stack_a, t_stack **stack_b);

int				find_median(int *str, int count);
void			sort_around_five(t_stack **stack_a,
						t_stack **stack_b, int count);
void			sort_four_or_five(t_stack **stack_a,
						t_stack **stack_b, int count);

int				ft_strnstr(char *str, char *arr, int n);
void			rotate_or_reverse(t_stack **stack_a,
					t_stack **stack_b, char *buffer);
void			swap_or_push(t_stack **stack_a,
					t_stack **stack_b, char *buffer);
void			is_sorted(t_stack **stack_a, t_stack **stack_b, int count);

int				get_next_line(int fd, char **line, char **save);
int				ft_save(char **line, char **save);
void			ft_repeat(char **temp, char **save, char *buffer, ssize_t size);
int				ft_return_zero(char **line, char **save,
					char *buffer, ssize_t size);
int				ft_return_one(char **line, char **save,
					char *buffer, ssize_t size);
int				ft_strlen(char *str);
void			ft_memcpy(char *dst, char *src, ssize_t n);
int				ft_check(char *str, ssize_t size);

#endif
