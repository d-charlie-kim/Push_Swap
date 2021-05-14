/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 20:01:41 by dokkim            #+#    #+#             */
/*   Updated: 2021/05/14 20:01:58 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char    **ft_split(char const *s, char c);
char    **ft_action(int **str, char const *s, char c, int a);
void    ft_free(int **str, int a);
int     ft_count(char const*s, char c);

#endif
