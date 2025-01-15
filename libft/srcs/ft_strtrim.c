/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 14:37:20 by lowatell          #+#    #+#             */
/*   Updated: 2024/11/05 12:25:00 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

static int	ft_char_in_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static int	ft_str_size(char const *str, char const *set)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	j = ft_strlen(str) - 1;
	if (j < 0)
		j = 0;
	while (ft_char_in_set(str[j], set) && str[j])
	{
		j--;
		count++;
	}
	while (ft_char_in_set(str[i], set) && str[i])
	{
		i++;
		count++;
	}
	if (count <= (int)ft_strlen(str))
		return (ft_strlen(str) - count);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	str = (char *)malloc(sizeof(char) * ft_str_size(s1, set) + 1);
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (ft_char_in_set(s1[i], set) && s1[i])
		i++;
	while (j + 1 <= ft_str_size(s1, set) && s1[i + j])
	{
		str[j] = s1[i + j];
		j++;
	}
	str[j] = '\0';
	return (str);
}
