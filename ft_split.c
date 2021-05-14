/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 03:35:07 by dokkim            #+#    #+#             */
/*   Updated: 2021/01/27 22:04:28 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_count(char const *s, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] == '\0')
		{
			return (count);
		}
		while (s[i] && s[i] != c)
			i++;
		count = count + 1;
	}
	return (count);
}

void	ft_free(int **str, int a)
{
	while (a >= 0)
	{
		free(str[a]);
		a--;
	}
	free(str);
}

char	**ft_action(int **str, char const *s, char c, int a)
{
	int i;
	int	first;
	int	last;

	i = 0;
	while (a < ft_count(s, c))
	{
		while (s[i] == c && s[i])
			i++;
		first = i;
		while (s[i] != c && s[i])
			i++;
		last = i;
		str[a] = (char *)malloc(sizeof(int));
		if (!str[a])
		{
			ft_free(str, a);
			return (NULL);
		}
		str[a][last - first] = '\0';
		last++;
		while (--last != first)
			str[a][last - first - 1] = s[last - 1];
		a++;
	}
	return (str);
}

char	**ft_split(char const *s, char c)
{
	int		*str;
	int		size;
	
	size = ft_count(s, c);
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	if (ft_action(str, s, c) == NULL)
		return (NULL);
	str[size + 1] = NULL;
	return (str);
}