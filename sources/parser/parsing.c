/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelvign <gdelvign@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 21:55:52 by jgasparo          #+#    #+#             */
/*   Updated: 2024/07/05 12:51:15 by gdelvign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
**	Save map from .cub (raw_file)
*/
static void	ft_save_map(t_data *data)
{
	int	y;
	int	size;
	int	start;

	y = 0;
	start = data->file->start;
	size = data->file->end - data->file->start;
	data->map->map = (char **)malloc(sizeof(char *) * (size + 1));
	if (!data->map->map)
		ft_error(MEM, STR_MEM, data);
	while (y < size)
	{
		data->map->map[y] = ft_strdup(data->file->raw_file[start++]);
		if (data->map->map[y][(ft_strlen(data->map->map[y]) - 1)] == 10)
			ft_memset(data->map->map[y]
				+ (ft_strlen(data->map->map[y]) - 1), 0, 1);
		y++;
	}
	data->map->map[y] = NULL;
	ft_get_y_x_max(data);
}

/*
**	Counts the number of lines in the file
*/
static void	ft_get_size_file(t_data *data)
{
	char	*line;

	ft_open_fd(data);
	while (data->file->fd)
	{
		data->file->size++;
		line = get_next_line(data->file->fd);
		if (!line)
			break ;
		free(line);
	}
	ft_close_fd(data);
}

/*
**	Save the .cub file into char **raw_file
*/
static void	ft_save_file(t_data *data)
{
	char	*line;
	int		y;

	y = 0;
	ft_get_size_file(data);
	data->file->raw_file = (char **)malloc(sizeof(char *) * data->file->size);
	if (!data->file->raw_file)
		ft_error(MEM, STR_MEM, data);
	ft_open_fd(data);
	while (data->file->fd)
	{
		line = get_next_line(data->file->fd);
		if (!line)
			break ;
		data->file->raw_file[y] = ft_strdup(line);
		free(line);
		y++;
	}
	data->file->raw_file[y] = NULL;
	ft_close_fd(data);
}

static void	ft_raw_map_to_mtx(t_data *data)
{
	int	i;
	int	j;

	data->mtx = (int **)malloc(data->map->y_size * sizeof(int *));
	if (!data->mtx)
		ft_error(MEM, STR_MEM, data);
	i = 0;
	while (i < data->map->y_size)
	{
		data->mtx[i] = (int *)malloc(data->map->x_size * sizeof(int));
		j = 0;
		while (j < data->map->x_size)
		{
			if (ft_isdigit(data->map->square_map[i][j]))
				data->mtx[i][j] = data->map->square_map[i][j] - '0';
			else
				data->mtx[i][j] = 0;
			j++;
		}
		i++;
	}
}

/*
**	Configures the map with these steps:
**	- Transforms the .cub fd into a raw_file
**	- Parses raw_file to get textures/colors + map delimitation
**	- Saves map
**	- Checks if there's a player in the map
**	- Checks if map is enclosed by walls
**	- Converts raw map (char) into a integer matrix for raycasting
*/
void	ft_setup_map(t_data *data)
{
	ft_save_file(data);
	ft_parsing_raw_map(data);
	ft_save_map(data);
	ft_check_player(data);
	ft_check_map(data);
	ft_raw_map_to_mtx(data);
}
