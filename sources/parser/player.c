/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgasparo <jgasparo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 00:33:39 by jgasparo          #+#    #+#             */
/*   Updated: 2024/06/29 19:22:03 by jgasparo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
**	Check if there is a player in the map.
**	If true -> save his position and orientation
*/
void	ft_check_player(t_data *data)
{
	int		y;
	int		x;

	y = -1;
	while (data->map->map[++y])
	{
		x = -1;
		while (data->map->map[y][++x])
		{
			if (ft_orientation_player(data->map->map[y][x]))
			{
				if (data->map->player.orientation != NONE)
					ft_errno(MANY_PLAYERS, data);
				else
				{
					data->map->player.orientation = data->map->map[y][x];
					data->map->player.position[Y] = y;
					data->map->player.position[X] = x;
				}
			}
		}
	}
	if (data->map->player.orientation == NONE)
		ft_errno(NO_PLAYER, data);
}
