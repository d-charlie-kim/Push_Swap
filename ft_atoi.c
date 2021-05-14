/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 03:38:24 by dokkim            #+#    #+#             */
/*   Updated: 2020/12/23 20:03:11 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(char *str)
{
	int i;
	int minus;
	int atoi_number;

	i = 0;
	minus = 1;
	atoi_number = 0;
	while (str[i] == '\t' || str[i] == '\v'
	|| str[i] == '\n' || str[i] == '\r'
	|| str[i] == '\f' || str[i] == ' ')
	{
		i++;
	}
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			minus *= -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		atoi_number = atoi_number * 10 + (str[i] - '0');
		i++;
	}
	return (atoi_number * minus);
}
