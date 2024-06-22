/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgasparo <jgasparo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 11:53:43 by jgasparo          #+#    #+#             */
/*   Updated: 2024/06/22 20:53:31 by jgasparo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// atoi en u_int8 (0-255) pour handle la data color + checker si not digit

static int  ft_space_letter(char c)
{
	// if (flag && (c == 'F' || c == 'C'))
	//     return (1);
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

u_int8_t ft_atoi_color(char *s, int *flag)
{
	int         i;
	u_int8_t    sign;
	u_int8_t    nb;

	i = 0;
	sign = 1;
	// if (ft_space_letter(s[0], 1))
	// 	i++;
	nb = 0;
	while (ft_space_letter(s[i]))
		i++;
	if (s[i] == '-' || s[i] == '+')
		if (s[i++] == '-')
			sign = -1;
		// return ((*flag)++);
	while (s[i])
	{
		if (ft_isdigit(s[i]))
			nb = (s[i++] - '0') + (nb * 10);
		else if (s[i] == '\n')
			break ;
		else
			return ((*flag)++);
	}
	return (nb * sign);
}