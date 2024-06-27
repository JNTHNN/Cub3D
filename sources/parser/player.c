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


void	ft_cpy_attr(double dest[2], double src[2])
{
	dest[0] = src[0];
	dest[1] = src[1];
}

void	ft_set_player_attributes(t_data *data, char orientation, int x, int y)
{
	data->map->player.orientation = orientation;
	data->map->player.position[Y] = y;
	data->map->player.position[X] = x;
	if (orientation == N)
	{
		ft_cpy_attr(data->map->player.direction, data->o_attributes.north.dir);
		ft_cpy_attr(data->map->player.pov, data->o_attributes.north.pov);
	}
	else if (orientation == S)
	{
		ft_cpy_attr(data->map->player.direction, data->o_attributes.south.dir);
		ft_cpy_attr(data->map->player.pov, data->o_attributes.south.pov);
	}
	else if (orientation == E)
	{
		ft_cpy_attr(data->map->player.direction, data->o_attributes.east.dir);
		ft_cpy_attr(data->map->player.pov, data->o_attributes.east.pov);
	}
	else
	{
		ft_cpy_attr(data->map->player.direction, data->o_attributes.west.dir);
		ft_cpy_attr(data->map->player.pov, data->o_attributes.west.pov);
	}
}

bool	ft_check_orientation(char c)
{
	if (c == N || c == S || c == E || c == W)
		return (true);
	return (false);
}

void	ft_check_player(t_data *data)
{
	int			x;
	int			y;
	char		**map;

	map = data->map->map;
	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (ft_check_orientation(map[y][x]))
			{
				if (data->map->player.orientation != NONE)
					ft_errno(MANY_PLAYERS, data);
				else
					ft_set_player_attributes(data, map[y][x], x, y);
			}
		}
	}
	if (data->map->player.orientation == NONE)
		ft_errno(NO_PLAYER, data);
	printf("PLAYER IS %c\n", data->map->player.orientation);
}
