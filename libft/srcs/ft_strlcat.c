/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 23:51:39 by lowatell          #+#    #+#             */
/*   Updated: 2024/11/05 12:24:17 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < dstsize && dst[i])
		i++;
	j = 0;
	while ((i + j + 1) < dstsize && src[j])
	{
		dst[j + i] = src[j];
		j++;
	}
	if (i < dstsize)
		dst[i + j] = '\0';
	j = 0;
	while (src[j])
		j++;
	return (i + j);
}
