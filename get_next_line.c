/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdmessa <abdmessa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:32:42 by abdmessa          #+#    #+#             */
/*   Updated: 2023/11/23 20:19:14 by abdmessa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_check_line(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == c)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_nl(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

char	*get_next_line(int fd)
{
	char		*buf;
	char		*tmp;
	static char	*stock;
	int			reader;
	char		*ret;

	reader = 1;
	if (BUFFER_SIZE < 1 || fd > 1024 || fd < 0)
		return (NULL);
	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	while (ft_check_line(stock, '\n') == 0 && reader > 0)
	{
		reader = read(fd, buf, BUFFER_SIZE);
		if (reader == -1)
			return (free(buf), NULL);
		tmp = stock;
		buf[reader] = '\0';
		stock = ft_strjoin(tmp, buf);
	}
	ret = ft_substr(stock, 0, ft_nl(stock) + 1);
	tmp = stock;
	stock = ft_substr(tmp, ft_nl(tmp) + 1, (ft_strlen(tmp) - ft_nl(tmp)));
	return (free(tmp), free(buf), ret);
}
/*
int	main(void)
{
	int		fd;
	char	*str;

	fd = open("fd.txt", O_RDONLY);
	str = NULL;
	//get_next_line(fd);
	while ((str = get_next_line(fd)))
	{
		printf("ligne : %s", str);
		free(str);
	}
	free(str);
}*/
