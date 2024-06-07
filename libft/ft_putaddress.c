/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddress.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelvign <gdelvign@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:05:50 by gdelvign          #+#    #+#             */
/*   Updated: 2024/01/16 10:23:11 by gdelvign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_putaddress(void *ptr, size_t *counter)
{
	unsigned long long	u_ptr;

	if (ft_putchar('0', counter))
		return (EXIT_FAILURE);
	if (ft_putchar('x', counter))
		return (EXIT_FAILURE);
	u_ptr = (unsigned long long)ptr;
	if (ft_putulong(u_ptr, HEX_BASE_LOW, counter))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
