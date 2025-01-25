/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:30:08 by lowatell          #+#    #+#             */
/*   Updated: 2025/01/25 14:09:23 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/pipex.h"

int	init_file(char **av, t_pipex *bag)
{
	int	fd;

	fd = 0;
	if (!av[1] || !av[4] || access(av[1], F_OK) == -1)
		return (0);
	bag->cmd1.file = av[1];
	if (!bag->cmd1.file)
		return (0);
	if (access(av[4], F_OK) == -1)
	{
		fd = open(av[4], O_CREAT | O_WRONLY, 0644);
		if (fd == -1)
			return (0);
	}
	bag->cmd2.file = av[4];
	if (!bag->cmd2.file)
		return (0);
	return (1);
}

int	get_pathcmd(t_pipex *bag, t_cmd *cmd)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = NULL;
	while (bag->path[i])
	{
		tmp = ft_strjoin(bag->path[i], "/");
		if (!tmp)
			return (2);
		tmp = ft_strjoin(tmp, cmd->cmd);
		if (!tmp)
			return (free(tmp), 2);
		if (access(tmp, X_OK) == 0)
		{
			cmd->pathcmd = ft_strdup(tmp);
			if (!cmd->pathcmd)
				return (free(tmp), 2);
			return (free(tmp), 1);
		}
		i++;
	}
	return (0);
}

int	init_cmd(char **av, t_pipex *bag)
{
	if (!av[2] || !av[3])
		return (0);
	bag->cmd1.cmd = av[2];
	if (!bag->cmd1.cmd)
		return (0);
	bag->cmd2.cmd = av[3];
	if (!bag->cmd2.cmd)
		return (0);
	return (1);
}

int	init_all(char **av, t_pipex *bag)
{
	if (!init_cmd(av, bag))
		return (0);
	if (!get_pathcmd(bag, &bag->cmd1))
		return (0);
	if (!get_pathcmd(bag, &bag->cmd2))
		return (0);
	if (!init_file(av, bag))
		return (0);
	return (1);
}

int	parsing(int ac, char **av, char **env, t_pipex *bag)
{
	int		i;
	char	**path;

	path = NULL;
	if (ac != 5)
		return (ft_printf("wrong number of arguments\n"), 0);
	i = -1;
	while (env[++i])
	{
		if (ft_strnstr(env[i], "PATH=", 5))
		{
			path = ft_split(env[i] + 5, ':');
			if (!path)
				return (0);
			break ;
		}
	}
	if (!path)
		return (0);
	bag->path = path;
	if (init_all(av, bag))
		return (1);
	return (0);
}
