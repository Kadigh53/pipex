/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_fcts_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 22:46:27 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/02/01 12:50:59 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*absolute_path(char **p, char *cmd)
{
	int		i;
	int		ret;
	char	*str;

	if (!*p || !p)
		return (NULL);
	i = 0;
	ret = 1;
	while ((ret != 0) && (p[i] != NULL))
	{
		str = ft_strjoin(p[i], "/");
		ret = access(ft_strjoin(str, cmd), F_OK);
		i++;
	}
	if (!p[i])
		return (NULL);
	str = ft_strjoin(str, cmd);
	return (str);
}

char	*path(char *cmd, char *envp[])
{
	int		i;
	char	**p;
	int		ret;
	char	*str;

	i = 0;
	ret = 1;
	p = NULL;
	while (envp && envp[i] != NULL)
	{
		if (ft_strstr(envp[i], "PATH"))
		{
			p = ft_split(envp[i] + 5, ':');
			break ;
		}
		i++;
	}
	str = absolute_path(p, cmd);
	return (str);
}
