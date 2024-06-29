/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgasparo <jgasparo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 00:17:01 by jgasparo          #+#    #+#             */
/*   Updated: 2024/06/28 23:39:05 by jgasparo         ###   ########.fr       */
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

int	ft_orientation_player(char c)
{
	return (c == N || c == S || c == W || c == E);
}

void	ft_get_size_map(t_data *data)
{
	int		y;
	char	**map;

	// ligne la plus longue -> x_size
	y = -1;
	map = data->map->map;
	while (map[++y])
	{
		if (ft_strlen(map[y]) > (size_t)data->map->x_size)
		{
			printf("la taille %zu\n", ft_strlen(map[y]));
			data->map->x_size = ft_strlen(map[y]); // a corriger
		}
	}
	// printf("laligne ici est [%s]\n", map[y]);
	while (!map[y] || (!ft_strchr(map[y], WALL) && !ft_strchr(map[y], GROUND)))
		y--;
	data->map->y_size = y + 1; // a corriger
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

int	ft_notmap(char *s, t_data *data)
{
	// printf("RRR [%s][%d]\n", s, ft_strncmp(s, "\n", ft_strlen(s)));
	if (!ft_strncmp(s, data->info->ceiling, ft_strlen(s))
		|| !ft_strncmp(s, data->info->floor, ft_strlen(s))
		|| !ft_strncmp(s, data->info->texture_north, ft_strlen(s))
		|| !ft_strncmp(s, data->info->texture_south, ft_strlen(s))
		|| !ft_strncmp(s, data->info->texture_east, ft_strlen(s))
		|| !ft_strncmp(s, data->info->texture_west, ft_strlen(s))
		|| !ft_strncmp(s, "\n", ft_strlen(s)))
			return (1);
	return (0);
}

int	ft_delimiter_map(t_data *data, int flag)
{
	int	y;

	y = 0;
	if (flag)
		y = data->file->start;
	while (data->file->raw_file[y++])
	{
		if ((!ft_notmap(data->file->raw_file[y], data) && !flag)
			|| (ft_notmap(data->file->raw_file[y], data) && flag))
			break ;
	}
	return (y);
}

void	ft_parsing_raw_map(t_data *data)
{
	// maintenant j'ai un char ** qui rpz le file cub
	// a partir de ce dernier, je dois recup les lignes contenant les infos
	// je dois comparer ligne par ligne
	int	y;
	int	flag;

	y = -1;
	flag = 0;
	while (data->file->raw_file[++y])
	{
		ft_check_data(data->file->raw_file[y], data, &flag);
	}
	if (flag != 6)
		ft_errno(MISSING, data);
	data->file->start = ft_delimiter_map(data, 0); // faire flag START
	data->file->end = ft_delimiter_map(data, 1); // faire flag END
	y = data->file->start;
	printf("%s\n", data->info->texture_north);
	ft_fill_color(data);
	ft_get_info_texture(data);

}
