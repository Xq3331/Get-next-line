/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 08:42:00 by pfaria-d          #+#    #+#             */
/*   Updated: 2022/11/17 15:16:38 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*line_reader(int fd, char *buff, char *line)
{
	char	*str;

	str = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!str)
		return (0);
	read(fd, buff, BUFFER_SIZE);
	buff[BUFFER_SIZE] = '\0';
	line = ft_strjoin(line, buff);
	while (ft_strchr(buff, '\n') == 0)
	{
		read(fd, buff, BUFFER_SIZE);
		buff[BUFFER_SIZE] = '\0';
		str = buff;
		line = ft_strjoin(line, buff);
		free(str);
	}
	return (line);
}

int	line_parser(char *line, int i)
{
	if (ft_strchr(line + i, '\n'))
		return (0);
	line = ft_substr(line, i, ft_strlen(line)
			- ft_strlen(ft_strchr(line + i, '\n')));
	return (ft_strlen(line) - ft_strlen(ft_strchr(line + i, '\n')));
}

char	*get_next_line(int fd)
{
	char		*buff;
	int			i;
	static char	*line;

	i = 0;
	if (!(BUFFER_SIZE > 0) || !fd)
		return (0);
	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (0);
	if (read(fd, buff, BUFFER_SIZE) == 0)
		return (0);
	line_reader(fd, buff, line);
	i += line_parser(line, i);
	return (line);
}
