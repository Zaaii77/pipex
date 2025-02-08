/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 12:59:10 by lowatell          #+#    #+#             */
/*   Updated: 2025/02/08 13:27:59 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/pipex.h"

void	exit_msg(char *str, int n)
{
	ft_printf("%s", str);
	exit(n);
}

void	parent(char **av, char **env, int *pfd)
{
	char	**cmd;
	int		fd;

	fd = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd == -1)
		exit_msg("Open failed\n", 2);
	dup2(fd, STDOUT_FILENO);
	close(fd);
	dup2(pfd[0], STDIN_FILENO);
	close(pfd[0]);
	close(pfd[1]);
	cmd = get_cmd(av[3], env);
	if (!cmd)
		exit(2);
	if (execve(cmd[0], cmd, 0) == -1)
	{
		free_tab(cmd);
		exit_msg("Execve failed\n", 2);
	}
}

void	child(char **av, char **env, int *pfd)
{
	char	**cmd;
	int		fd;

	fd = open(av[1], O_RDONLY, 0777);
	if (fd == -1)
		exit_msg("Open failed\n", 2);
	dup2(fd, STDIN_FILENO);
	close(fd);
	dup2(pfd[1], STDOUT_FILENO);
	close(pfd[0]);
	close(pfd[1]);
	cmd = get_cmd(av[2], env);
	if (!cmd)
		exit(2);
	if (execve(cmd[0], cmd, 0) == -1)
	{
		free_tab(cmd);
		exit_msg("Execve failed\n", 2);
	}
}

int	main(int ac, char **av, char **env)
{
	int	pfd[2];
	int	pid;

	if (ac != 5)
	{
		ft_printf("Error\nWrong amount of arguments.\n");
		ft_printf("Ex: ./pipex <file1> <cmd1> <cmd2> <file2>\n");
		exit(1);
	}
	if (pipe(pfd) == -1)
		return (ft_printf("Pipe error\n"), 2);
	pid = fork();
	if (pid == -1)
		exit_msg("Fork error\n", 2);
	if (pid == 0)
		child(av, env, pfd);
	parent(av, env, pfd);
	ft_printf("big test bg");
	return (0);
}
