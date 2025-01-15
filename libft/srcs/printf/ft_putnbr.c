/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 11:12:48 by lowatell          #+#    #+#             */
/*   Updated: 2024/11/05 12:28:04 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/ft_printf.h"

size_t	ft_putnbase(ssize_t nbr, char *str)
{
	size_t	len;
	ssize_t	size;

	size = ft_strlen(str);
	len = ft_nbr_len(nbr, str);
	if (nbr < 0)
	{
		nbr = nbr * -1;
		ft_putchar('-');
	}
	if (nbr >= size)
	{
		ft_putnbase(nbr / size, str);
		ft_putnbase(nbr % size, str);
	}
	if (nbr < size)
		ft_putchar(str[nbr % size]);
	return (len);
}
