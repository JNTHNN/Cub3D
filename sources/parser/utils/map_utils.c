/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelvign <gdelvign@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 00:17:01 by jgasparo          #+#    #+#             */
/*   Updated: 2024/06/26 22:01:21 by gdelvign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_wall(char c, int flag)
{
	if ((flag == TOP || flag == BOT) && c != 49 && c != 32)
		return (1);
	if ((flag == LEFT || flag == RIGHT) && c != 49)
		return (1);
	return (0);
}

void	ft_get_size_map(t_data *data, char **map)
{
	int	y;

	// ligne la plus longue -> x_size
	y = -1;
	while (map[++y])
	{
		if (ft_strlen(map[y]) > (size_t)data->map->x_size)
			data->map->x_size = ft_strlen(map[y]);
	}
	printf("laligne ici est [%s]\n", map[y]);
	while (!map[y] || (!ft_strchr(map[y], WALL) && !ft_strchr(map[y], GROUND)))
		y--;
	data->map->y_size = y + 1;
}

void	ft_basic_check(t_data *data)
{
	int		y;
	int		x;
	char	**map;
	
	y = -1;
	map = data->map->map;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] != WALL && map[y][x] != GROUND && map[y][x] != SPACE && map[y][x] != N && map[y][x] != S && map[y][x] != W && map[y][x] != E)
				ft_errno(WRONG_CHAR, data);
		}
	}
}

void	ft_search_map_content(t_data *data)
{
	char	*line;
	int		flag;

	flag = 0;
	while (data->map->fd)
	{
		// mettre un compteur pour le start de la map | A REFAIRE
		data->map->start++;
		line = get_next_line(data->map->fd);
		if (!line || !ft_strncmp(line, "1", 1)) // pb si la 1ere ligne de la map commence par " 1"
			break ;
		ft_check_data(line, data, &flag);
		free(line);
	}
	// checker si toutes les data de info sont init sinon error
	if (flag != 6)
		ft_errno(MISSING, data); // a voir si je detaille l'erreur data
}
