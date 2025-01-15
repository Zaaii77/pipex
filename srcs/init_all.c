/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 22:13:03 by lowatell          #+#    #+#             */
/*   Updated: 2025/01/15 22:53:38 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/pipex.h"

void	error_manager(t_pipex *bag)
{
	if (bag->file[0])
		free(bag->file[0]);
	if (bag->file[1])
		free(bag->file[1]);
	if (bag->cmd[0])
		free(bag->cmd[0]);
	if (bag->cmd[1])
		free(bag->cmd[1]);
	if (bag->path)
		free(bag->path);
	exit(2);
}

char	*get_env(char **env)
{
	int		i;
	char	*path;
	char	**tab;

	i = 0;
	while (env[i])
	{
		if (ft_strnstr(env[i], "PATH=", 5))
			break;
		else
			i++;
	}
	if (!env[i])
		return (NULL);
	tab = ft_split(env[i], ':');
	if (!tab)
		return (NULL);
	tab[0] = ft_strjoin(tab[0], "/");
	if (!tab[0])
		return (free_tab(tab), NULL);
	path = ft_strdup(tab[0]);
	if (!path)
		return (free_tab(tab), NULL);
	return (free_tab(tab), path);
}

int	init_all(char **av, char **env, t_pipex *bag)
{
	bag->cmd[0] = ft_strdup(av[1]);
	if (!bag->cmd[0])
		return (2);
	bag->cmd[1] = ft_strdup(av[4]);
	if (!bag->cmd[1])
		return (error_manager(bag), 2);
	bag->cmd[2] = 0;
	bag->file[0] = ft_strdup(av[2]);
	if (!bag->file[0])
		return (error_manager(bag), 2);
	bag->file[1] = ft_strdup(av[3]);
	if (!bag->file[1])
		return (error_manager(bag), 2);
	bag->file[2] = 0;
	bag->path = get_env(env);
	if (!bag->path)
		error_manager(bag);
	ft_printf("%s\n", bag->path);
	return (1);
}
