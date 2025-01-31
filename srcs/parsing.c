/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:30:08 by lowatell          #+#    #+#             */
/*   Updated: 2025/01/31 14:23:26 by lowatell         ###   ########.fr       */
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

char	**final_tab(char **tmp, char *file)
{
	int		i;
	char	**tab;

	if (!file || !tmp || !*tmp)
		return (NULL);
	i = 0;
	tab = NULL;
	while (tmp[i])
		i++;
	tab = (char **)malloc(sizeof(char *) * i + 1);
	if (!tab)
		return (NULL);
	i = -1;
	while (tmp[++i])
	{
		tab[i] = ft_strdup(tmp[i]);
		if (!tab[i])
			return (free_tab(tab), NULL);
	}
	tab[i] = ft_strdup(file);
	if (!tab[i])
		return (free_tab(tab), NULL);
	tab[i + 1] = 0;
	return (tab);
}

char	**access_test(char *str, char *file)
{
	char	**tab;
	char	**tmp;

	if (!str || !file)
		return (NULL);
	tab = NULL;
	if (access(str, X_OK) == 0)
	{
		tmp = ft_split(str, ' ');
		if (!tmp)
			return (NULL);
		tab = final_tab(tmp, file);
		return (free(tmp), tmp = NULL, tab);
	}
	tmp = ft_split(str, ' ');
	if (!tmp)
		return (NULL);
	if (access(tmp[0], X_OK) == 0)
	{
		tab = final_tab(tmp, file);
		return (free(tmp), tmp = NULL, tab);
	}
	return (free(tab), tab = NULL, NULL);
}

char	**get_path(char *cmd, char **env, char *file)
{
	int		i;
	char	*tmp;
	char	**part_path;
	char	**path;

	part_path = access_test(cmd, file);
	if (part_path)
		return (part_path);
	path = split_path(env);
	i = -1;
	while(path[++i])
	{
		tmp = ft_strjoin(path[i], "/");
		if (!tmp)
			return (free_tab(path), NULL);
		tmp = ft_strjoin(tmp, cmd);
		if (!tmp)
			return (free_tab(path), NULL);
		part_path = access_test(tmp, file);
		if (part_path)
			return (free(tmp), part_path);
		free(part_path);
		free(tmp);
	}
	return (NULL);
}
