/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgasparo <jgasparo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 00:33:39 by jgasparo          #+#    #+#             */
/*   Updated: 2024/06/26 00:34:17 by jgasparo         ###   ########.fr       */
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
			if (ft_position_player(map[y][x]))
			{
				if (data->map->player != NONE)
					ft_errno(MANY_PLAYERS, data);
				else
					data->map->player = map[y][x];
			}
		}
	}
	if (data->map->player == NONE)
		ft_errno(NO_PLAYER, data);
	else
		printf("PLAYER IS %c\n", data->map->player);
}
