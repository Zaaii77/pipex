/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 11:57:37 by lowatell          #+#    #+#             */
/*   Updated: 2024/11/05 12:27:54 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/ft_printf.h"

static size_t	ft_type(char c, va_list *args)
{
	if (c == 's')
		return (ft_putstr(va_arg(*args, char *)));
	else if (c == 'c')
		return (ft_putchar(va_arg(*args, int)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbase(va_arg(*args, int), "0123456789"));
	else if (c == 'u')
		return (ft_putnbase(va_arg(*args, unsigned int), "0123456789"));
	else if (c == '%')
		return (ft_putchar('%'));
	else if (c == 'p')
		return (ft_print_address(va_arg(*args, void *), "0123456789abcdef"));
	else if (c == 'X')
		return (ft_putnbase(va_arg(*args, unsigned int), "0123456789ABCDEF"));
	else if (c == 'x')
		return (ft_putnbase(va_arg(*args, unsigned int), "0123456789abcdef"));
	else
		return (ft_putchar(c));
}

int	ft_printf(const char *str, ...)
{
	size_t	count;
	va_list	args;

	if (!str)
		return (0);
	count = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%' && *(str + 1) != '\0')
		{
			str++;
			count += ft_type(*str, &args);
		}
		else
			count += ft_putchar(*str);
		str++;
	}
	va_end(args);
	return (count);
}
