/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 11:19:09 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/02/01 16:43:57 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	errors(int a)
{
	if (a == 2)
		write(STDERR_FILENO, "pipe failed\n", 13);
	else if (a == 1)
		write(STDERR_FILENO, "files failed at opening\n", 31);
	else if (a == 3)
		write(STDERR_FILENO, "fork failed\n", 13);
	else if (a == 4)
		write(STDERR_FILENO, "command not found\n", 17);
	else if (a == 5)
		write(STDERR_FILENO, "incompatible nbr of arguments\n", 31);
	else if (a == 6)
		write(STDERR_FILENO, "execution failed\n", 17);
	exit(1);
}

void	execute(char *cmd, char *envp[])
{
	char	*cmd_path;
	char	**p;

	p = ft_split(cmd, ' ');
	cmd_path = path(p[0], envp);
	if (!cmd_path)
		errors(4);
	execve(cmd_path, p, envp);
}

void	process(char *cmd, char*envp[])
{
	int	pid;
	int	pipefd[2];
	int	n;

	n = pipe(pipefd);
	if (n == -1)
		errors(2);
	pid = fork();
	if (pid == -1)
		errors(3);
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
	char	*line;
	int		pipefd[2];

	line = NULL;
	pipe(pipefd);
	while (1)
	{
		write(1, "heredoc> ", 9);
		line = get_next_line(0);
		if (line == NULL)
			exit(1);
		if (ft_strcmp(av[2], line, ft_strlen(line) - 1) == 0)
			break ;
		write(pipefd[1], line, ft_strlen(line));
	}
	close(pipefd[1]);
	return (pipefd[0]);
}

int	main(int ac, char *av[], char *envp[])
{
	t_ppx_b	varbs_strct;
	int		i;

	if (ac >= 5)
	{
		i = 2;
		if (ft_strcmp(av[1], "here_doc", 8) == 0)
		{
			varbs_strct.fdinf = herdoc(av);
			i++;
		}
		else
			varbs_strct.fdinf = open(av[1], O_RDWR);
		varbs_strct.fdoutf = open(av[ac - 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
		if (varbs_strct.fdinf < 0 || varbs_strct.fdoutf < 0)
			errors(1);
		dup2(varbs_strct.fdinf, STDIN_FILENO);
		process(av[i++], envp);
		while (i < ac - 2)
			process(av[i++], envp);
		dup2(varbs_strct.fdoutf, STDOUT_FILENO);
		execute(av[i], envp);
		errors (6);
	}
	errors(5);
}
