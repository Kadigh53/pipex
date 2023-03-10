/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 11:48:57 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/02/01 15:53:05 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	errors(int a)
{
	if (a == 1)
		write(STDERR_FILENO, "\033[1;31mERROR:pipe failed\n", 25);
	else if (a == 2)
		write(STDERR_FILENO, "\033[1;31mERROR:files failed at opening\n", 37);
	else if (a == 3)
		write(STDERR_FILENO, "\033[1;31mERROR:fork failed\n", 25);
	else if (a == 4)
		write(STDERR_FILENO, "\033[1;31mERROR:command not found\n", 31);
	else if (a == 5)
		write(STDERR_FILENO, "\033[1;31mERROR:execution failed\n", 29);
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

void	processes(int fds[], char *av[], char *envp[])
{
	int	pid1;

	pid1 = fork();
	if (pid1 == -1)
		errors(3);
	if (pid1 == 0)
	{
		close(fds[0]);
		dup2(fds[1], STDOUT_FILENO);
		execute(av[2], envp);
	}
	else
	{
		wait(NULL);
		close(fds[1]);
		dup2(fds[0], STDIN_FILENO);
		execute(av[3], envp);
	}
}

int	main(int ac, char *av[], char *envp[])
{
	int		i;
	t_ppx	varbs_t;

	if (ac == 5)
	{
		if (!envp[0] || !envp)
			errors(4);
		varbs_t.fdinf = open(av[1], O_RDWR);
		varbs_t.fdoutf = open(av[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
		if (varbs_t.fdinf < 0 || varbs_t.fdinf < 0)
			errors(2);
		dup2(varbs_t.fdinf, STDIN_FILENO);
		dup2(varbs_t.fdoutf, STDOUT_FILENO);
		i = pipe(varbs_t.fds);
		if (i == -1)
			errors(1);
		processes(varbs_t.fds, av, envp);
		errors(5);
	}
	write(STDERR_FILENO, "\033[1;31mERROR:incompatible numbre of argmnts", 43);
	exit(1);
}
