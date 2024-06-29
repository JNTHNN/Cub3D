/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgasparo <jgasparo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 21:55:52 by jgasparo          #+#    #+#             */
/*   Updated: 2024/06/29 02:59:03 by jgasparo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	}
	ft_close_fd(data);
}

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
		y++;
	}
	data->file->raw_file[y] = NULL;
	ft_close_fd(data);
	// for (int u = 0; data->file->raw_file[u]; u++) // pour voir la save du fd -> raw_file
	// 	printf("[%d][%s]\n", u, data->file->raw_file[u]);
}

void	ft_setup_map(t_data *data)
{
	//	transformation fd -> raw_files
	ft_save_file(data);
	//	parsing le raw_file pour avoir textures/colors + delimitation de la map
	ft_parsing_raw_map(data);
	// save la map de data->map->map
	ft_save_map(data);
	//	on check le player
	ft_check_player(data);
	// maintenant on check la validité de la map (murs autor)
	ft_check_map(data);	
	ft_print_struct(data);
}


