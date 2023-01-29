/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 20:57:32 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/01/04 21:59:09 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_line_index(char *p)
{
	int	i;

	i = 0;
	if (!p)
		return (0);
	while (p[i])
	{
		if (p[i] == '\n')
			return (i + 1);
		i++;
	}
	return (i);
}

int	a_newline(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*read_line(int fd, int Buffer_size, char *p)
{
	char	*str;
	int		i;

	i = 1;
	str = malloc(Buffer_size + 1);
	if (!str)
		return (NULL);
	while (!a_newline(p) && i != 0)
	{
		i = read(fd, str, BUFFER_SIZE);
		if (i < 0)
		{
			free(str);
			free(p);
			return (NULL);
		}
		str[i] = '\0';
		p = ft_strjoin_gnl(p, str);
	}
	free(str);
	return (p);
}

char	*get_next_line(int fd)
{
	static char	*p;
	char		*tmp;
	char		*line;
	int			i;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > FDMAX)
		return (NULL);
	i = 0;
	p = read_line(fd, BUFFER_SIZE, p);
	i = get_line_index(p);
	line = ft_substr_gnl(p, 0, i);
	tmp = ft_substr_gnl(p, i, ft_strlen_gnl(p) - i);
	free(p);
	p = tmp;
	return (line);
}
