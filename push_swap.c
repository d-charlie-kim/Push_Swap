/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 19:54:50 by dokkim            #+#    #+#             */
/*   Updated: 2021/05/14 19:54:52 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     ft_split(char **argv, int *stack)
{
    int i;
    int j;
    int k;
    int minus;

    i = 1;
    k = 0;
    while (argv[i])
    {
        j = 0;
        while (argv[i][j])
            {
                minus = 1;
                while (argv[i][j] == ' ' && argv[i][j])
                    j++;
                if (argv[i][j] == '-' && argv[i][j])
                {
                    j++;
                    minus = -1;
                }
                while (argv[i][j] >= 48 && argv[i][j] <=57 && argv[i][j])
                {
                    stack[k] = (stack[k] * 10) + argv[i][j] - '0';
                    j++;
                }
                stack[k] = stack[k] * minus;
                k++;
            }
        i++;
    }
    return (0);
}

int     ft_count(char **argv)
{
    int     count;
    int     i;
    int     j;

    i = 1;
    count = 0;
    while (argv[i])
    {
        j = 0;
        while (argv[i][j])
            {
                while (argv[i][j] == ' ' && argv[i][j])
                    j++;
                if (argv[i][j] == '-' && argv[i][j])
                    j++;
                if (argv[i][j] < 48 && argv[i][j] > 57 && argv[i][j])
                    return (-1);
                count++;
                while (argv[i][j] >= 48 && argv[i][j] <=57 && argv[i][j])
                    j++;
            }
            i++;
    }
    return (count);
}

int     ft_putstr(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {   
        write(1, &str[i], 1);
        i++;
    }
    write(1, "\n", 1);
    return (0);
}

int     ft_duplicate(int *stack, int count)
{
    int i;
    int j;

    i = 0;
    while (i < count)
    {
        j = i + 1;
        while (j < count)
        {
            if (stack[i] == stack[j])
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}

int     main(int argc, char **argv)
{
    int     *stack;
    int     Error_check;
    int     count;
    int     i;

    if (argc < 2)
        return (ft_putstr("Error"));
    count = ft_count(argv);
    if (count <= 0)
        return (ft_putstr("Error"));
    stack = (int *)malloc(sizeof(int) * count);
    if (!stack)
        return (ft_putstr("Memory Error"));
    i = 0;
    while (i < count)
        stack[i++] = 0;
    if (ft_split(argv, stack))
        return (ft_putstr("Error"));
    if (ft_duplicate(stack, count))
       return (ft_putstr("Error"));
    int a = 0;
    while (a < count)
    {
        printf("ag : %d\n", stack[a]);
        a++;
    }
    // if (ft_sort(stack))
    //     return (ft_putstr("Error"));
    return (0);
}