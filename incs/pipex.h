/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:11:55 by lowatell          #+#    #+#             */
/*   Updated: 2025/01/15 22:27:12 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "../libft/incs/libft.h"

typedef	struct s_pipex
{
	char	*path;
	char	*cmd[3];
	char	*file[3];
}	t_pipex;


int parsing(int ac, char **av);
int	init_all(char **av, char **env, t_pipex *bag);

#endif