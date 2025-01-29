/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:22:32 by lowatell          #+#    #+#             */
/*   Updated: 2025/01/25 22:45:53 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/pipex.h"

int	main(int ac, char **av, char **env)
{
	t_pipex	bag;

	if (!parsing(ac, av, env, &bag))
		return (0);
	ft_printf("%s\n%s\n", bag.cmd1.file, bag.cmd1.cmd);
	execve(bag.cmd1.file, bag.cmd1.cmd, 0);
	return (0);
}
