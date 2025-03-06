/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 12:59:10 by lowatell          #+#    #+#             */
/*   Updated: 2025/03/06 17:48:25 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/pipex.h"

void	close_fds(int *fd)
{
	close(fd[0]);
	close(fd[1]);
}

void	parent(char **av, char **env, int *pfd)
{
	char	**cmd;
	int		fd;

	if (!av[3] || !av[3][0])
		exit(1);
	fd = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd == -1)
		exit(1);
	dup2(fd, STDOUT_FILENO);
	close(fd);
	dup2(pfd[0], STDIN_FILENO);
	close_fds(pfd);
	cmd = get_cmd(av[3], env);
	execve(cmd[0], cmd, env);
	free_tab(cmd);
	exit(127);
}

void	child(char **av, char **env, int *pfd)
{
	char	**cmd;
	int		fd;

	if (!av[2] || !av[2][0])
		exit(1);
	fd = open(av[1], O_RDONLY, 0777);
	if (fd == -1)
		exit(1);
	dup2(fd, STDIN_FILENO);
	close(fd);
	dup2(pfd[1], STDOUT_FILENO);
	close_fds(pfd);
	cmd = get_cmd(av[2], env);
	execve(cmd[0], cmd, env);
	free_tab(cmd);
	exit(1);
}

int	main(int ac, char **av, char **env)
{
	int		pfd[2];
	int		status;
	pid_t	pid2;
	pid_t	pid;

	if (ac != 5)
		return (ft_printf("Ex: ./pipex <file1> <cmd1> <cmd2> <file2>\n"), 1);
	if (pipe(pfd) == -1)
		return (2);
	pid = fork();
	if (pid == -1)
		return (close(pfd[0]), close(pfd[1]), 1);
	if (pid == 0)
		child(av, env, pfd);
	pid2 = fork();
	if (pid2 == -1)
		return (close(pfd[0]), close(pfd[1]), 1);
	if (pid2 == 0)
		parent(av, env, pfd);
	close_fds(pfd);
	waitpid(pid, 0, 0);
	waitpid(pid2, &status, 0);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (0);
}
