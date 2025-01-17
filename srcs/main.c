/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:22:32 by lowatell          #+#    #+#             */
/*   Updated: 2025/01/17 08:26:52 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/pipex.h"

int main(int ac, char **av, char **env)
{
	t_pipex	bag;
	int		i;

    if (!parsing(ac, av))
		return (0);
	init_all(av, env, &bag);
	i = access(ft_strjoin(bag.path, "cat ."), X_OK);
	ft_printf("%s is %d\n", bag.cmd[0], i);
}
