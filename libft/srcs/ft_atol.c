/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 19:00:46 by lowatell          #+#    #+#             */
/*   Updated: 2024/11/25 20:18:44 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

long long	ft_atol(const char *s)
{
	unsigned long long	nbr;
	int					sign;
	size_t				i;

	i = 0;
	sign = 1;
	nbr = 0;
	while (s[i] == 32 || (s[i] >= 9 && s[i] <= 13))
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(s[i]))
	{
		nbr = (nbr * 10) + (s[i] - 48);
		i++;
	}
	return (nbr * sign);
}
