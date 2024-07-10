/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgasparo <jgasparo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 11:21:52 by jgasparo          #+#    #+#             */
/*   Updated: 2024/07/10 11:07:49 by jgasparo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
/*
**	Check top / bot wall
*/
static void	ft_check_top_bot(char **map, t_data *data)
{
	int	x;

	x = 0;
	while (map[0][x])
	{
		if (ft_wall(map[0][x], TOP))
			ft_error(MAP_NOT_CLOSE, STR_MAP_NOT_CLOSE, data);
		x++;
	}
	x = 0;
	while (map[data->map->y_size - 1][x])
	{
		if (ft_wall(map[data->map->y_size - 1][x], BOT))
			ft_error(MAP_NOT_CLOSE, STR_MAP_NOT_CLOSE, data);
		x++;
	}
}

/*
**	Check the walls around the map
*/
void	ft_check_walls(t_data *data)
{
	char	**map;
	int		y;
	int		last_char_index;

	map = data->map->map;
	ft_check_top_bot(map, data);
	y = 0;
	while (map[y])
	{
		if (ft_wall(map[y][0], LEFT))
			ft_error(MAP_NOT_CLOSE, STR_MAP_NOT_CLOSE, data);
		last_char_index = ft_strlen(map[y]) - 1;
		while (last_char_index >= 0 && ft_space_letter(map[y][last_char_index]))
			last_char_index--;
		if (last_char_index >= 0 && ft_wall(map[y][last_char_index], RIGHT))
			ft_error(MAP_NOT_CLOSE, STR_MAP_NOT_CLOSE, data);
		y++;
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
