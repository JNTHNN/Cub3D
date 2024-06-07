/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelvign <gdelvign@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:56:19 by gdelvign          #+#    #+#             */
/*   Updated: 2024/01/16 10:23:11 by gdelvign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_dispatch(const char *s, va_list lst, size_t *counter)
{
	if (*(s + 1) == 'c')
		return (ft_printchar(lst, counter));
	if (*(s + 1) == 's')
		return (ft_printstr(lst, counter));
	if (*(s + 1) == 'd' || *(s + 1) == 'i')
		return (ft_printnbr(lst, counter));
	if (*(s + 1) == 'u')
		return (ft_printuint(lst, counter));
	if (*(s + 1) == 'p')
		return (ft_printaddress(lst, counter));
	if (*(s + 1) == 'x' || *(s + 1) == 'X')
		return (ft_printhex(lst, counter, *(s + 1)));
	if (*(s + 1) == '%')
		return (ft_putchar('%', counter));
	return (EXIT_SUCCESS);
}

int	ft_printf(const char *s, ...)
{
	va_list	parameters;
	size_t	char_printed;

	char_printed = 0;
	va_start(parameters, s);
	while (*s)
	{
		if (*s != '%')
		{
			if (ft_putchar(*s, &char_printed))
				return (-1);
		}
		if (*s == '%')
		{
			if (ft_dispatch(s, parameters, &char_printed))
				return (-1);
			s++;
		}
		s++;
	}
	va_end(parameters);
	return (char_printed);
}
