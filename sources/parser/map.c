/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgasparo <jgasparo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 00:12:46 by jgasparo          #+#    #+#             */
/*   Updated: 2024/06/29 02:43:14 by jgasparo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_get_y_x_max(t_data *data)
{
	int	y;
	int	temp;

	y = 0;
	temp = 0;
	while (data->map->map[y])
	{
		if ((int)ft_strlen(data->map->map[y]) > temp)
			temp = ft_strlen(data->map->map[y]);
		y++;
	}
	data->map->y_size = y;
	data->map->x_size = temp;
}

void	ft_save_map(t_data *data)
{
	// ici on sauve la map
	int	y;
	int	size;
	int	start;

	y = 0;
	start = data->file->start;
	size = data->file->end - data->file->start;
	data->map->map = (char **)malloc(sizeof(char *) * (size));
	if (!data->map->map)
		ft_errno(MEM, data);
	while (y < size)
	{
		data->map->map[y] = ft_strdup(data->file->raw_file[start++]);
		if (data->map->map[y][(ft_strlen(data->map->map[y]) - 1)] == 10)
			ft_memset(data->map->map[y] + (ft_strlen(data->map->map[y]) - 1), 0, 1); // remove le \n
		y++;
	}
	data->map->map[y] = NULL;
	// besoin de connaitre le y_max y et y_max x
	ft_get_y_x_max(data);
}

void	ft_square_map(t_data *data)
{
	int		x_max;
	int		y_max;
	int		x;
	int		y;
	char	**square_map;
	
	y = 0;
	x_max = data->map->x_size;
	y_max = data->map->y_size;
	data->map->square_map = (char **)malloc(sizeof(char *) * y_max + 1); // a proteger
	square_map = data->map->square_map;
	while (y < y_max)
	{
		square_map[y] = (char *)malloc(sizeof(char) * x_max + 1); // a proteger
		ft_memset(square_map[y], EMPTY, x_max);
		ft_memset(square_map[y] + (x_max), 0, 1);
		printf("SQUARE [%d]\t[%s]\n",y, square_map[y]);
		y++;
	}
	y = 0;
	while (y < y_max && data->map->map[y])
	{
		x = 0;
		while (x < x_max && data->map->map[y][x])
		{
			if (data->map->map[y][x] != '\0' && data->map->map[y][x] != SPACE)
				square_map[y][x] = data->map->map[y][x];
			x++;
		}
		printf("SQUARE2[%d]\t[%s]\n", y, square_map[y]);
		y++;
	}
	square_map[y] = NULL;
	for(int u=0 ; square_map[u]; u++)
		printf("OK [%s]\n",square_map[u]);
}

void	ft_check_map(t_data *data)
{
	ft_basic_check(data);
	ft_check_walls(data);
	ft_square_map(data);
	ft_backtrack_wall(data);
	ft_backtrack_player(data);
}
