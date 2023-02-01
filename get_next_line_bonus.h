/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 20:57:56 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/01/31 14:53:00 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>

char	*get_next_line(int fd);
size_t	ft_strlen_gnl(char *s);
int		a_newline(char *s);
char	*ft_substr_gnl(char *s, unsigned int start, size_t len);
char	*ft_strjoin_gnl(char *s1, char *s2);
char	*ft_strdup(char *s1);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# ifndef FDMAX
#  define FDMAX 10240
# endif

#endif
