/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgasparo <jgasparo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 11:21:52 by jgasparo          #+#    #+#             */
/*   Updated: 2024/06/29 02:39:13 by jgasparo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_check_walls(t_data *data)
{
	char	**map;
	int		x;
	int		y;

	x = 0;
	map = data->map->map;
	while (map[0][x] && map[0][++x])
		if (ft_wall(map[0][x], TOP))
				ft_errno(MAP_NOT_CLOSE, data);
	while (map[data->map->y_size - 1][x] && map[data->map->y_size - 1][++x])
		if (ft_wall(map[data->map->y_size - 1][x], BOT))
				ft_errno(MAP_NOT_CLOSE, data);
	y = 0;
	while (map[y] && map[++y])
		if (ft_wall(map[y][0], LEFT) || ft_wall(map[y][ft_strlen(map[y]) - 1], RIGHT))
			ft_errno(MAP_NOT_CLOSE, data);
}

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
				if (map[y][x - 1] == EMPTY || map[y][x + 1] == EMPTY || map[y - 1][x] == EMPTY || map[y + 1][x] == EMPTY)
					ft_errno(MAP_NOT_CLOSE, data); // ici on peut print les coor de la case open
			}
		}
	}
}

void	ft_backtrack_player(t_data *data)
{
	int	y;
	int	x;
	char	**map;
	
	y = data->map->player.position[0];
	x = data->map->player.position[1];
	map = data->map->square_map;

	if (map[y][x - 1] == EMPTY || map[y][x + 1] == EMPTY || map[y - 1][x] == EMPTY || map[y + 1][x] == EMPTY)
		ft_errno(AMB_PLAYER, data);
}
