/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 23:37:36 by lowatell          #+#    #+#             */
/*   Updated: 2024/11/07 17:43:08 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/ft_printf.h"

size_t	ft_putstr(char *str)
{
	int		i;
	size_t	count;

	if (!str)
		return (ft_putstr("(null)"));
	i = 0;
	count = 0;
	while (str[i])
	{
		count += ft_putchar((int)str[i]);
		i++;
	}
	return (count);
}
