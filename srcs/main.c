/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 12:59:10 by lowatell          #+#    #+#             */
/*   Updated: 2025/02/06 20:18:06 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/pipex.h"

int	main(int ac, char **av, char **env)
{
	int		pfd[2];
	char	**cmd;

	if (ac != 5)
	{
		ft_printf("Error\nWrong amount of arguments.\n");
		ft_printf("Ex: ./pipex <file1> <cmd1> <cmd2> <file2>\n");
		exit(1);
	}
	if (pipe(pfd) == -1)
		return (ft_printf("Pipe error\n"), 2);
	cmd = get_cmd(av[1], env);
	return (0);
}
