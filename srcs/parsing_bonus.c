/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 13:10:36 by lowatell          #+#    #+#             */
/*   Updated: 2025/02/10 23:59:04 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/pipex.h"

char	**get_path(char **env)
{
	char	**path;
	char	*tmp;
	int		i;

	i = -1;
	tmp = NULL;
	while (env[++i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
		{
			tmp = ft_strdup(env[i]);
			break ;
		}
	}
	if (!tmp)
		return (NULL);
	path = ft_split(tmp, ':');
	if (!path)
		return (free(tmp), NULL);
	return (free(tmp), path);
}

char	*find_path(char *av, char **path)
{
	int		i;
	char	*tmp;
	char	*ttmp;

	i = -1;
	while (path[++i])
	{
		tmp = ft_strjoin(path[i], "/");
		if (!tmp)
			exit(2);
		ttmp = ft_strjoin(tmp, av);
		if (!ttmp)
		{
			free(tmp);
			exit(2);
		}
		free(tmp);
		if (access(ttmp, X_OK) == 0)
			return (ttmp);
		free(ttmp);
	}
	return (NULL);
}

char	**get_cmd(char *av, char **env)
{
	char	**cmd;
	char	**path;
	char	*tmp;

	cmd = ft_split(av, ' ');
	if (!cmd)
		exit(2);
	if (access(cmd[0], X_OK) == 0)
		return (cmd);
	path = get_path(env);
	if (!path)
	{
		free_tab(cmd);
		exit(2);
	}
	tmp = find_path(cmd[0], path + 5);
	if (!tmp)
		return (free_tab(path), cmd);
	free(cmd[0]);
	cmd[0] = ft_strdup(tmp);
	if (!cmd[0])
		free_tab(cmd + 1);
	return (free_tab(path), free(tmp), cmd);
}
