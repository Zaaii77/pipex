/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:22:32 by lowatell          #+#    #+#             */
/*   Updated: 2025/01/30 18:40:28 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/pipex.h"

int	main(int ac, char **av, char **env)
{
	t_pipex	*bag;

	bag = NULL;
	bag = (t_pipex *)malloc(sizeof(bag));
	bag = parsing(ac, av, env, bag);
	if (!bag)
		return (0);
	ft_printf("%s, %s", bag->cmd1.cmd, bag->cmd1.file);
	return (0);
}
