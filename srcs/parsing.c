/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:30:08 by lowatell          #+#    #+#             */
/*   Updated: 2025/01/31 11:59:22 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/pipex.h"

char	**split_path(char **env)
{	
	char	**split_path;
	int		i;

	i = 0;
	while (env[i] && ft_strnstr(env[i], "PATH=", 5) == 0)
		i++;
	if (!env[i])
		return (NULL);
	split_path = ft_split(env[i] + 5, ':');
	if (!split_path)
		return (NULL);
	return (split_path);
}

char	*get_path(char *cmd, char **env)
{
	int		i;
	char	*tmp;
	char	*part_path;
	char	**path;

	if (access(cmd, X_OK) == 0)
		return (cmd);
	path = split_path(env);
	i = 0;
	while(path[i])
	{
		tmp = ft_strjoin(path[i], "/");
		if (!tmp)
			return (free_tab(path), NULL);
		part_path = ft_strjoin(tmp, cmd);
		if (!part_path)
			return (free_tab(path), free(tmp), tmp = NULL, NULL);
		free(tmp);
		if (access(part_path, X_OK) == 0)
			return (part_path);
		free(part_path);
		part_path = NULL;
		i++;
	}
	return (NULL);
}
