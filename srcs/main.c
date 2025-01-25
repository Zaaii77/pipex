/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:22:32 by lowatell          #+#    #+#             */
/*   Updated: 2025/01/25 05:41:22 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/pipex.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int ac, char **av, char **env)
{
	t_pipex	bag;

    if (!parsing(ac, av, env, &bag))
 		return (0);
}
