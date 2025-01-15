/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:30:08 by lowatell          #+#    #+#             */
/*   Updated: 2025/01/15 17:20:55 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/pipex.h"

int is_file(char **av)
{
    int fd;

    fd = open(av[1], O_RDWR);
    if (fd == -1)
        return (ft_printf("Can't open %s\n", av[1]), 2);
    close(fd);
    fd = open(av[4], O_RDWR);
    if (fd == -1)
        return (ft_printf("Can't open %s\n", av[4]), 2);
    close(fd);
    return (1);
}

int parsing(int ac, char **av)
{
    if (ac != 5)
    {
        ft_printf("wrong number of arguments\n");
        return (0);
    }
    if (is_file(av) != 1)
        return (2);
    return (0);
}