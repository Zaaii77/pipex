/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:22:32 by lowatell          #+#    #+#             */
/*   Updated: 2025/01/24 17:43:51 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/pipex.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int ac, char **av, char **env)
{
	t_pipex	bag;

	parsing(ac, av, env, &bag);
    // if (!parsing(ac, av, env, &bag))
	// 	return (0);
	ft_printf("bag->path=%s\n", bag.path[0]);
	ft_printf("bag->cmd1.pathcmd = %s\nbag->cmd2.pathcmd = %s\n", bag.cmd1.pathcmd, bag.cmd2.pathcmd);
}
