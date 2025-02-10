/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 12:59:10 by lowatell          #+#    #+#             */
/*   Updated: 2025/02/10 15:57:04 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/pipex.h"

void	parent(char **av, char **env, int *pfd)
{
	char	**cmd;
	int		fd;

	fd = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd == -1)
		exit(2);
	dup2(fd, STDOUT_FILENO);
	close(fd);
	dup2(pfd[0], STDIN_FILENO);
	close(pfd[0]);
	close(pfd[1]);
	cmd = get_cmd(av[3], env);
	if (execve(cmd[0], cmd, env) == -1)
		free_tab(cmd);
}

void	child(char **av, char **env, int *pfd)
{
	char	**cmd;
	int		fd;

	fd = open(av[1], O_RDONLY, 0777);
	if (fd == -1)
		exit(2);
	dup2(fd, STDIN_FILENO);
	close(fd);
	dup2(pfd[1], STDOUT_FILENO);
	close(pfd[0]);
	close(pfd[1]);
	cmd = get_cmd(av[2], env);
	if (execve(cmd[0], cmd, env) == -1)
		free_tab(cmd);
}

int	main(int ac, char **av, char **env)
{
	int		pfd[2];
	pid_t	pid;

	if (ac != 5)
		return (ft_printf("Ex: ./pipex <file1> <cmd1> <cmd2> <file2>\n"), 1);
	if (pipe(pfd) == -1)
		return (2);
	pid = fork();
	if (pid == -1)
		return (close(pfd[0]), close(pfd[1]), 2);
	if (pid == 0)
		child(av, env, pfd);
	parent(av, env, pfd);
	waitpid(pid, 0, 0);
	return (0);
}
