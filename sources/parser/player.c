/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgasparo <jgasparo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 00:33:39 by jgasparo          #+#    #+#             */
/*   Updated: 2024/06/28 23:40:18 by jgasparo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_check_player(t_data *data)
{
	int		x;
	int		y;
	char	**map;
	
	map = data->map->map;
	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (ft_orientation_player(map[y][x]))
			{
				if (data->map->player.orientation != NONE)
					ft_errno(MANY_PLAYERS, data);
				else
				{
					data->map->player.orientation = map[y][x];
					data->map->player.position[0] = y;
					data->map->player.position[1] = x;
				}
			}
		}
	}
	if (data->map->player.orientation == NONE)
		ft_errno(NO_PLAYER, data);
	else
		printf("PLAYER IS %c\n", data->map->player.orientation); // a enlever
}
