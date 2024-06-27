/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelvign <gdelvign@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 00:33:39 by jgasparo          #+#    #+#             */
/*   Updated: 2024/06/27 08:01:23 by gdelvign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_set_player_attributes(t_player *player, double dirX, double dirY, double povX, double povY)
{
		player->direction[0] = dirX;
		player->direction[1] = dirY;
		player->pov[0] = povX;
		player->pov[1] = povY;
}

bool	ft_orientation_player(char c, t_player *player)
{
	if (c == N)
		ft_set_player_attributes(player, 0, -1, 0.66, 0);
	else if (c == S)
		ft_set_player_attributes(player, 0, 1, -0.66, 0);
	else if (c == E)
		ft_set_player_attributes(player, 1, 0, 0, -0.66);
	else if (c == W)
		ft_set_player_attributes(player, -1, 0, 0, 0.66);
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
