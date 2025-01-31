/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:30:08 by lowatell          #+#    #+#             */
/*   Updated: 2025/01/30 18:40:03 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/pipex.h"

int	get_command(t_pipex *bag, char **av)
{
	bag->cmd1.cmd = ft_split(av[2], ' ');
	if (!bag->cmd1.cmd)
		return (0);
	bag->cmd2.cmd = ft_split(av[3], ' ');
	if (!bag->cmd2.cmd)
		return (free_tab(bag->cmd1.cmd), 0);
	return (1);
}

t_pipex	*init_file(char **av, t_pipex *bag)
{
	int	fd;

	fd = 0;
	if (!av[1] || !av[4] || access(av[1], F_OK) == -1)
		return (0);
	bag->cmd1.file = ft_strdup(av[1]);
	if (!bag->cmd1.file)
		return (0);
	if (access(bag->cmd1.file, F_OK) == -1)
	{
		fd = open(av[4], O_CREAT | O_WRONLY, 0644);
		if (fd == -1)
			return (NULL);
		close(fd);
	}
	bag->cmd2.file = ft_strdup(av[4]);
	if (!bag->cmd2.file)
		return (NULL);
	return (bag);
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
		tmp = ft_strjoin(tmp, cmd->cmd[0]);
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

t_pipex	*init_all(char **av, t_pipex *bag)
{
	if (!get_command(bag, av))
		return (NULL);
	if (!get_pathcmd(bag, &bag->cmd1))
		return (NULL);
	if (!get_pathcmd(bag, &bag->cmd2))
		return (NULL);
	bag = init_file(av, bag);
	if (!bag)
		return (NULL);
	return (bag);
}

t_pipex	*parsing(int ac, char **av, char **env, t_pipex *bag)
{
	int		i;
	char	**path;

	path = NULL;
	if (ac != 5)
		return (ft_printf("wrong number of arguments\n"), NULL);
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
	bag = init_all(av, bag);
	if (!bag)
		return (NULL);
	return (bag);
}
