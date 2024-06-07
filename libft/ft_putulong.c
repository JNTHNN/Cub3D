/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putulong.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelvign <gdelvign@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 11:29:15 by gdelvign          #+#    #+#             */
/*   Updated: 2024/01/16 10:23:11 by gdelvign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_putulong(unsigned long long nb, char *base, size_t *counter)
{
	size_t	basesize;

	basesize = ft_strlen(base);
	if (nb < basesize)
	{
		if (ft_putchar(base[nb], counter))
			return (EXIT_FAILURE);
	}
	else
	{
		ft_putulong(nb / basesize, base, counter);
		if (ft_putchar(base[nb % basesize], counter))
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
