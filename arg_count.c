/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_count.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 02:15:24 by dokkim            #+#    #+#             */
/*   Updated: 2021/05/22 02:15:25 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		arg_count(char **argv, int count)
{
	int	i;
	int	j;
	int valid;

	i = 1;
	count = 0;
	while (argv[i])
	{
		valid = count;
		j = 0;
		while (argv[i][j])
		{
			while ((argv[i][j] < 48 || argv[i][j] > 57) && argv[i][j])
				j++;
			if (argv[i][j])
				count++;
			while (argv[i][j] >= 48 && argv[i][j] <= 57 && argv[i][j])
				j++;
		}
		i++;
		if (valid == count)
			ft_error("Error", NULL, NULL);
	}
	return (count);
}
