/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelvign <gdelvign@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 20:37:00 by jgasparo          #+#    #+#             */
/*   Updated: 2024/07/04 17:03:07 by gdelvign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_info	*ft_init_info(t_data *data)
{
	t_info	*info;

	info = (t_info *)malloc(sizeof(t_info));
	if (!info)
		ft_errno(MEM, data);
	info->floor = NULL;
	info->ceiling = NULL;
	info->texture_north = NULL;
	info->texture_south = NULL;
	info->texture_west = NULL;
	info->texture_east = NULL;
	return (info);
}

u_color	ft_init_color(void)
{
	u_color	rgb;

	rgb.s_value = 0;
	rgb.s_rgb.b = 0;
	rgb.s_rgb.g = 0;
	rgb.s_rgb.r = 0;
	return (rgb);
}

void	ft_init_player(t_player *player)
{
	player->position[0] = NONE;
	player->position[1] = NONE;
	player->direction[0] = UNSET;
	player->direction[1] = UNSET;
	player->fov[0] = UNSET;
	player->fov[1] = UNSET;
	player->orientation = NONE;
	player->move = 0U;
}

t_map	*ft_init_map(t_data *data, char *file)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		ft_errno(MEM, data);
	map->fd = -1;
	map->floor = ft_init_color();
	map->ceiling = ft_init_color();
	map->texture_north = NULL;
	map->texture_south = NULL;
	map->texture_west = NULL;
	map->texture_east = NULL;
	map->y_size = 0;
	map->x_size = 0;
	map->file = file;
	map->map = NULL;
	map->square_map = NULL;
	ft_init_player(&map->player);
	return (map);
}

t_file	*ft_init_file(t_data *data)
{
	t_file	*file;

	file = (t_file *)malloc(sizeof(t_file));
	if (!file)
		ft_errno(MEM, data);
	file->raw_file = NULL;
	file->fd = -1;
	file->size = 0;
	file->start = 0;
	return (file);
}
