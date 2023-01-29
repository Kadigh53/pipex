/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_fcts.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 10:58:03 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/01/12 22:26:17 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*absolute_path(char **p, char *cmd)
{
	int		i;
	int		ret;
	char	*str;

	if (!*p)
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
	char	*str;

	i = 0;
	p = NULL;
	while (envp[i] != NULL)
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
