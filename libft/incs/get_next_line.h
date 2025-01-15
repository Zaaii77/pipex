/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:48:28 by lowatell          #+#    #+#             */
/*   Updated: 2024/11/07 07:22:31 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define MAXINT 2147483647

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
size_t	strline_gnl(char *str);
size_t	strlen_gnl(char *str);
int		isline_gnl(char *str);

#endif
