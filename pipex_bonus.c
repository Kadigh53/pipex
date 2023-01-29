/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 11:19:09 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/01/29 21:36:46 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
#include <stdio.h>
#include <unistd.h>

void	errors(int a)
{
	if (a == 2)
		write(STDERR_FILENO, "pipe failed", 12);
	else if (a == 1)
		write(STDERR_FILENO, "files failed at opening", 30);
	else if (a == 3)
		write(STDERR_FILENO, "fork failed", 12);
	else if (a == 4)
		write(STDERR_FILENO, "command not found", 16);
	exit(1);
}

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
	int		ret;
	char	*str;

	i = 0;
	ret = 1;
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

void	execute(char *cmd, char *envp[])
{
	char	*cmd_path;
	char	**p;

	p = ft_split(cmd, ' ');
	cmd_path = path(p[0], envp);
	if (!cmd_path)
		errors(4);
	// dup2(fd, STDIN_FILENO);
	execve(cmd_path, p, envp);
}

void	process(char *cmd, char*envp[])
{
	int pid;
	int pipefd[2];
	int n;
		
	n = pipe(pipefd);
	pid = fork();
	if (pid == 0)
	{
		close(pipefd[0]);
		dup2(pipefd[1], STDOUT_FILENO);
		execute(cmd, envp);
	}
	else
	{
		wait(NULL);
		close(pipefd[1]);
		dup2(pipefd[0], STDIN_FILENO);
	}
}

int	herdoc(char *av[])
{
	char	*str;
	char	*line;
	int		pipefd[2];
	
	line = NULL;
	pipe(pipefd);
	while(ft_strcmp(line, av[2], ft_strlen(av[2])) != 0)
	{
		write(1, "heredoc> ", 9);
		line = get_next_line(0);
		if (ft_strcmp(line, av[2], ft_strlen(line)) == 0)
		{
			close(pipefd[1]);
			return (pipefd[0]);
		}
		if (ft_strcmp(line, av[2], ft_strlen(line)) != 0)
			write(pipefd[1], line, ft_strlen(line));
			// break;
	}
	close(pipefd[1]);
	return (pipefd[0]);
}

int main(int ac, char *av[], char *envp[])
{
	int		i;
	ppx_b_t varbs_strct;

	if (ac >= 5)
	{
		i = 2;
		varbs_strct.fdinf = herdoc(av);
		i++;
		// if (ft_strcmp(av[1], "here_doc", 8))
		// {
		// }
		// else
		// 	varbs_strct.fdinf = open(av[1], O_RDWR);
		varbs_strct.fdoutf = open(av[ac - 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
		if (varbs_strct.fdinf < 0 || varbs_strct.fdoutf < 0)
			errors(1);
		dup2(varbs_strct.fdinf, STDIN_FILENO);
		process(av[i++], envp);
		while ( i < ac - 2)
			process(av[i++], envp);
		dup2(varbs_strct.fdoutf, STDOUT_FILENO);
		execute(av[i], envp);
		return (0);
	}
	write(STDERR_FILENO, "incompatible nbr of arguments",30);
	exit(1);
}
