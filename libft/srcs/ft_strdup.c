/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 04:13:53 by lowatell          #+#    #+#             */
/*   Updated: 2024/11/05 12:23:57 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	size_t	j;
	char	*s2;

	i = 0;
	j = 0;
	while (s1[j])
		j++;
	s2 = (char *)malloc((sizeof(char) * j) + 1);
	if (!s2)
		return (NULL);
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
