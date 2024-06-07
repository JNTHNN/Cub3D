/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelvign <gdelvign@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 11:00:55 by gdelvign          #+#    #+#             */
/*   Updated: 2024/01/16 10:23:11 by gdelvign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_printstr(va_list lst, size_t *counter)
{
	void		*value;

	value = (char *)va_arg(lst, char *);
	if (!value)
		ft_putstr("(null)", counter);
	else
	{
		if (ft_putstr(value, counter))
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
