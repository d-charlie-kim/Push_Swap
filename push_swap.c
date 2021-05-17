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

int     ft_split(char **argv, t_stack *stack)
{
    t_stack *temp;
    int     i;
    int     j;
    int     k;
    int     minus;

    i = 1;
    temp = stack;
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
                k = 0;
                while (argv[i][j] >= 48 && argv[i][j] <=57 && argv[i][j])
                {
                    temp->number = (temp->number * 10) + argv[i][j] - '0';
                    k++;
                    j++;
                }
                if (k >= 11 || temp->number > 2147483648 || (temp->number == 2147483648 && minus == 1))
                {
                    //ft_lstclear(stack);
                    return (-1);
                }
                temp->number = temp->number * minus;
                temp->next = (t_stack *)malloc(sizeof(t_stack));
                if (!(temp->next))
                {
                    //ft_lstclear(stack);
                    return (-1);
                }
                temp = temp->next;
                temp->number = 0;
                temp->next = NULL;
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
                if ((argv[i][j] < 48 || argv[i][j] > 57) && argv[i][j])
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

int     ft_duplicate(t_stack *stack, int count)
{
    int i;
    t_stack *temp;
    t_stack *temp2;

    i = 0;
    temp = stack;
    while (temp->next != NULL)
    {
        temp2 = temp->next;
        while (temp2->next != NULL)
        {
            if (temp->number == temp2->number)
                return (1);
            temp2 = temp2->next;
        }
        temp = temp->next;
    }
    return (0);
}

int     main(int argc, char **argv)
{
    t_stack     *stack;
    int         count;

    if (argc < 2)
        return (ft_putstr("Error"));
    count = ft_count(argv);
    if (count <= 0)
        return (ft_putstr("Error"));
    stack = (t_stack *)malloc(sizeof(t_stack));
    if (!(stack))
        return (ft_putstr("Memory Error"));
    stack->next = NULL;
    if (ft_split(argv, stack))
        return (ft_putstr("Error"));
    if (ft_duplicate(stack, count))
    {
        //ft_lstclear(stack);
        return (ft_putstr("Error"));
    }
     while (stack->next != NULL)
     {
         printf("ag : %lld\n", stack->number);
         stack = stack->next;
     }
    // if (ft_sort(stack))
    // {
    //     ft_lstclear(stack);
    //     return (ft_putstr("Error"));
    // }
    return (0);
}