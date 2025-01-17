/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:30:08 by lowatell          #+#    #+#             */
/*   Updated: 2025/01/17 08:19:12 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/pipex.h"

int parsing(int ac, char **av)
{
    if (ac != 5)
    {
        ft_printf("wrong number of arguments\n");
        return (0);
    }
	ft_strlen(av[0]);
    return (1);
}