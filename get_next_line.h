/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 08:41:58 by pfaria-d          #+#    #+#             */
/*   Updated: 2022/11/17 15:15:12 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>

//BUFFER SETUP

//GNL utils
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_memcpy(void *d, const void *s, size_t size);
char	*ft_strdup(const char *s);
char	*ft_strchr(const char *str, int c);
char	*ft_substr(const char *s, unsigned int start, size_t len);

//GNL
size_t	ft_strlen(const char *str);
char	*get_next_line(int fd);
int		line_parser(char *line, int i);
char	*line_reader(int fd, char *buff, char *line);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

#endif
