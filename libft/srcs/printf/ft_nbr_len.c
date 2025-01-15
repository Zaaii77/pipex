/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 10:05:35 by lowatell          #+#    #+#             */
/*   Updated: 2024/11/05 12:27:44 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/ft_printf.h"

size_t	ft_nbr_len(long nbr, char *str)
{
	size_t	count;
	size_t	len;

	len = ft_strlen(str);
	count = 0;
	if (nbr < 0)
	{
		nbr = -nbr;
		count++;
	}
	if (nbr == 0)
		return (1);
	while (nbr > 0)
	{
		nbr /= len;
		count++;
	}
	return (count);
}
