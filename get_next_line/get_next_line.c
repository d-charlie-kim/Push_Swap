/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 22:18:14 by dokkim            #+#    #+#             */
/*   Updated: 2021/06/11 18:12:44 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		ft_return_one(char **line, char **save, char *buffer, ssize_t size)
{
	ssize_t	i;

	i = 0;
	while (buffer[i] != '\n')
		i++;
	if (!(*line = (char *)malloc(ft_strlen(*save) + (sizeof(char) * (i + 1)))))
	{
		free(*save);
		return (-1);
	}
	**line = '\0';
	ft_memcpy(*line, *save, ft_strlen(*save));
	ft_memcpy(*line, buffer, i);
	free(*save);
	if (!(*save = (char *)malloc(sizeof(char) * (size - i))))
	{
		free(*line);
		return (-1);
	}
	**save = '\0';
	ft_memcpy(*save, buffer + i + 1, size - i - 1);
	return (1);
}

int		ft_return_zero(char **line, char **save, char *buffer, ssize_t size)
{
	if (!(*line = (char *)malloc(ft_strlen(*save)
	+ (sizeof(char) * (size + 1)))))
	{
		free(*save);
		return (-1);
	}
	**line = '\0';
	ft_memcpy(*line, *save, ft_strlen(*save));
	ft_memcpy(*line, buffer, size);
	free(*save);
	*save = NULL;
	return (0);
}

void	ft_repeat(char **temp, char **save, char *buffer, ssize_t size)
{
	if (!(*temp = (char *)malloc(ft_strlen(*save)
	+ (sizeof(char) * (size + 1)))))
	{
		free(*save);
		return ;
	}
	**temp = '\0';
	ft_memcpy(*temp, *save, ft_strlen(*save));
	ft_memcpy(*temp, buffer, size);
	free(*save);
	*save = *temp;
}

int		ft_save(char **line, char **save)
{
	ssize_t	i;
	char	*temp;

	i = 0;
	while ((*save)[i] != '\n')
		i++;
	if (!(*line = (char *)malloc(sizeof(char) * (i + 1))))
	{
		free(*save);
		return (-1);
	}
	**line = '\0';
	ft_memcpy(*line, *save, i);
	if (!(temp = (char *)malloc(sizeof(char) * (ft_strlen(*save) - i))))
	{
		free(*line);
		free(*save);
		return (-1);
	}
	*temp = '\0';
	ft_memcpy(temp, *save + i + 1, ft_strlen(*save) - i - 1);
	free(*save);
	*save = temp;
	return (1);
}

int		get_next_line(int fd, char **line, char **save)
{
	char		buffer[256];
	ssize_t		size;
	char		*temp;

	if (ft_check(*save, ft_strlen(*save)))
		return (ft_save(line, save));
	size = 0;
	while (size >= 0)
	{
		size = read(fd, buffer, 256);
		if (ft_check(buffer, size))
			return (ft_return_one(line, save, buffer, size));
		if (size == 256)
			ft_repeat(&temp, save, buffer, size);
		else if (size >= 0)
			return (ft_return_zero(line, save, buffer, size));
	}
	free(save);
	return (-1);
}
