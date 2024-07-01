/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgasparo <jgasparo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 00:17:01 by jgasparo          #+#    #+#             */
/*   Updated: 2024/07/01 15:11:02 by jgasparo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
**	Check if it's a wall | return 0 if true
*/
int	ft_wall(char c, int flag)
{
	if ((flag == TOP || flag == BOT) && c != WALL && c != SPACE && c != '\t')
		return (1);
	if ((flag == LEFT || flag == RIGHT) && c != WALL)
		return (1);
	return (0);
}

/*
**	Check if player orientation is valid
*/
int	ft_orientation_player(char c)
{
	return (c == N || c == S || c == W || c == E);
}

/*
**	Check for other inaccurate characters
*/
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
			if (map[y][x] != WALL
				&& map[y][x] != GROUND
				&& map[y][x] != SPACE
				&& map[y][x] != N
				&& map[y][x] != S
				&& map[y][x] != W
				&& map[y][x] != E
				&& map[y][x] != '\t')
				ft_errno(WRONG_CHAR, data);
		}
	}
}

/*
**	Check if the line is the datas line
*/
int	ft_notmap(char *s, t_data *data)
{
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

/*
**	Delimits the map
*/
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

/*
**	Extract data from raw file and find map coordinates
*/
void	ft_parsing_raw_map(t_data *data)
{
	int	y;
	int	flag;

	y = -1;
	flag = 0;
	while (data->file->raw_file[++y])
		ft_check_data(data->file->raw_file[y], data, &flag);
	if (flag != 6)
		ft_errno(MISSING, data);
	data->file->start = ft_delimiter_map(data, START);
	data->file->end = ft_delimiter_map(data, END);
	y = data->file->start;
	ft_fill_color(data);
	ft_get_info_texture(data);
}
