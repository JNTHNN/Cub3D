/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelvign <gdelvign@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 21:55:52 by jgasparo          #+#    #+#             */
/*   Updated: 2024/07/03 14:48:24 by gdelvign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
**	Save map from .cub (raw_file)
*/
static void	ft_save_map(t_data *data)
{
	// ici on sauve la map
	int	y;
	int	size;
	int	start;

	y = 0;
	start = data->file->start;
	size = data->file->end - data->file->start;
	data->map->map = (char **)malloc(sizeof(char *) * (size + 1));
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

/*
**	Check if file extension is .cub
*/
void	ft_check_arg(int argc, char **argv)
{
	char	*file_extension;

	if (argc > 2)
		ft_errno(TOO_MANY, NULL);
	else if (argc < 2)
		ft_errno(NO_MAP, NULL);
	else
	{
		file_extension = ft_strrchr(MAP, DOT);
		if (!file_extension
			|| (ft_strlen(file_extension) != 4
				|| ft_strncmp(file_extension, CUB, ft_strlen(CUB))))
			ft_errno(WRONG_EXT, NULL);
	}
}

/*
**	Counts the number of lines in the file
*/
void	ft_get_size_file(t_data *data)
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
void	ft_save_file(t_data *data)
{
	char	*line;
	int		y;

	y = 0;
	ft_get_size_file(data);
	data->file->raw_file = (char **)malloc(sizeof(char *) * data->file->size);
	if (!data->file->raw_file)
		ft_errno(MEM, data);
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
	// for (int u = 0; data->file->raw_file[u]; u++) // pour voir la save du fd -> raw_file
	// 	printf("[%d][%s]\n", u, data->file->raw_file[u]);
}

/*
**	Configure the map with these steps:
**	- Transform the .cub fd into a raw_file
**	- Parse raw_file to get textures/colors + map delimitation
**	- Save map
**	- Check if there's a player in the map
**	- Checks if map is enclosed by walls
*/
void	ft_setup_map(t_data *data)
{
	ft_save_file(data);
	ft_parsing_raw_map(data);
	ft_save_map(data);
	ft_check_player(data);
	ft_check_map(data);	
	ft_print_struct(data);
	ft_raw_map_to_mtx(data);
	ft_set_textures(data);
}
