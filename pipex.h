/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 17:09:00 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/01/29 13:53:41 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>

size_t	ft_strlen(char *s);
char	**ft_split(char *s, char c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strstr(char *haystack, char *needle);
char	*ft_substr(char *s, unsigned int start, size_t len);
int		ft_strcmp(char *s1, char *s2, int n);
char	*absolute_path(char **p, char *cmd);
char	*absolute_path(char **p, char *cmd);
char	*path(char *cmd, char *envp[]);

typedef struct pipex
{
	int	fdinf;
	int	fdoutf;
	int	fds[2];

} ppx_t;


# endif

