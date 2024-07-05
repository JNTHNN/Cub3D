/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelvign <gdelvign@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 11:21:52 by jgasparo          #+#    #+#             */
/*   Updated: 2024/07/05 12:52:36 by gdelvign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
**	Check the walls around the map
*/
void	ft_check_walls(t_data *data)
{
	char	**map;
	int		x;
	int		y;

	x = 0;
	map = data->map->map;
	while (map[0][x] && map[0][++x])
		if (ft_wall(map[0][x], TOP))
			ft_error(MAP_NOT_CLOSE, STR_MAP_NOT_CLOSE, data);
	x = 0;
	while (map[data->map->y_size - 1][x] && map[data->map->y_size - 1][++x])
		if (ft_wall(map[data->map->y_size - 1][x], BOT))
			ft_error(MAP_NOT_CLOSE, STR_MAP_NOT_CLOSE, data);
	y = 0;
	while (map[y] && map[++y])
	{
		x = 0;
		while (ft_wall(map[y][x++], LEFT))
			if (ft_wall(map[y][x], LEFT))
				ft_error(MAP_NOT_CLOSE, STR_MAP_NOT_CLOSE, data);
	}
}

/*
**	Check if ground (0) boxes are not surrounded by empty (2) boxes
*/
void	ft_backtrack_wall(t_data *data)
{
	int		y;
	int		x;
	char	**map;

	y = 0;
	map = data->map->square_map;
	while (y++ < data->map->y_size && map[y])
	{
		x = 0;
		while (x++ < data->map->x_size && map[y][x])
		{
			if (map[y][x] == GROUND)
			{
				if (map[y][x - 1] == EMPTY || map[y][x + 1] == EMPTY
					|| map[y - 1][x] == EMPTY || map[y + 1][x] == EMPTY)
					ft_error(MAP_NOT_CLOSE, STR_MAP_NOT_CLOSE, data);
			}
		}
	}
}

/*
**	Check that the player square (N-S-W-D) is not surrounded by empty (2) squares
*/
void	ft_backtrack_player(t_data *data)
{
	int		y;
	int		x;
	char	**map;

	y = data->map->player.position[Y];
	x = data->map->player.position[X];
	map = data->map->square_map;
	if (map[y][x - 1] == EMPTY || map[y][x + 1] == EMPTY
		|| map[y - 1][x] == EMPTY || map[y + 1][x] == EMPTY)
		ft_error(AMB_PLAYER, STR_AMB_PLAYER, data);
}
