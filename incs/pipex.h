/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:11:55 by lowatell          #+#    #+#             */
/*   Updated: 2025/01/30 18:39:38 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "../libft/incs/libft.h"

typedef struct s_cmd
{
	char	**cmd;
	char	*pathcmd;
	char	*file;
}	t_cmd;

typedef struct s_pipex
{
	char			**path;
	struct s_cmd	cmd1;
	struct s_cmd	cmd2;
}	t_pipex;

t_pipex	*parsing(int ac, char **av, char **env, t_pipex *bag);

#endif