/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgasparo <jgasparo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:20:46 by jgasparo          #+#    #+#             */
/*   Updated: 2024/07/09 23:09:42 by jgasparo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_arrlen(char **tab)
{
	int	i;

	i = 0;
	while (tab && tab[i])
		i++;
	return (i);
}

size_t	ft_strlen_cub3d(char *s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s && s[i])
	{
		if (s[i] == '\t')
			j += 4;
		else
			j++;
		i++;
	}
	return (j);
}
