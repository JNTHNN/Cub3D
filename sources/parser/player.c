/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelvign <gdelvign@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 00:33:39 by jgasparo          #+#    #+#             */
/*   Updated: 2024/06/26 22:16:36 by gdelvign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	ft_orientation_player(char c, t_player *player)
{
	if (c == N)
	{
		player->direction[0] = 0;
		player->direction[1] = -1;
		player->pov[0] = 0.66;
		player->pov[1] = 0;
	}
	else if (c == S)
	{
		player->direction[0] = 0;
		player->direction[1] = 1;
		player->pov[0] = -0.66;
		player->pov[1] = 0;
	}
	else if (c == E)
	{
		player->direction[0] = 1;
		player->direction[1] = 0;
		player->pov[0] = 0;
		player->pov[1] = -0.66;
	}
	else if (c == W)
	{
		player->direction[0] = -1;
		player->direction[1] = 0;
		player->pov[0] = 0;
		player->pov[1] = 0.66;
	}
	else 
		return (false);
	return (true);
}

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
			if (ft_orientation_player(map[y][x], &data->map->player))
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
		printf("PLAYER IS %c\n", data->map->player.orientation);
}
