/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelvign <gdelvign@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 11:53:43 by jgasparo          #+#    #+#             */
/*   Updated: 2024/07/04 21:53:40 by gdelvign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_space_letter(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

u_int8_t	ft_atoi_color(char *s, int *flag)
{
	int			i;
	u_int8_t	sign;
	u_int8_t	nb;

	i = 0;
	sign = 1;
	nb = 0;
	if (ft_strlen(s) == 1 && !ft_isdigit(s[0]))
		return ((*flag)++);
	while (ft_space_letter(s[i]))
		i++;
	if (s[i] == '-' || s[i] == '+')
		if (s[i++] == '-')
			sign = -1;
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
