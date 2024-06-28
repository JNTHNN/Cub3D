/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelvign <gdelvign@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 20:37:00 by jgasparo          #+#    #+#             */
/*   Updated: 2024/06/27 07:44:57 by gdelvign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_info	*ft_init_info(t_data *data)
{
	t_info	*info;

	info = (t_info *)malloc(sizeof(t_info));
	if (info == NULL)
		ft_errno(MEM, data);
	info->floor = NULL;
	info->ceiling = NULL;
	info->texture_north = NULL;
	info->texture_south = NULL;
	info->texture_west = NULL;
	info->texture_east = NULL;
	return (info);
}

t_orientation_att	ft_init_o_attributes(void)
{
	t_orientation_att	attributes;

	attributes.north.dir[X] = 0;
	attributes.north.dir[Y] = -1;
	attributes.north.pov[1] = 0.71;
	attributes.north.pov[0] = 0;
	attributes.south.dir[X] = 0;
	attributes.south.dir[Y] = 1;
	attributes.south.pov[1] = -0.71;
	attributes.south.pov[0] = 0;
	attributes.east.dir[X] = 1;
	attributes.east.dir[Y] = 0;
	attributes.east.pov[1] = 0;
	attributes.east.pov[0] = 0.71;
	attributes.west.dir[X] = -1;
	attributes.west.dir[Y] = 0;
	attributes.west.pov[1] = 0;
	attributes.west.pov[0] = -0.71;
	return (attributes);
}

t_data	*ft_init_data(char *file)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (data == NULL)
		ft_errno(MEM, data);
	data->mlx = NULL;
	data->win = NULL;
	data->img = (t_img *)malloc(sizeof(t_img));
	if (data->img == NULL)
		ft_errno(MEM, data);
	data->img->mlx_img = NULL;
	data->img->addr = NULL;
	data->img->bpp = 0;
	data->img->line_len = 0;
	data->img->endian = 0;
	data->map = ft_init_map(data, file);
	data->info = ft_init_info(data);
	data->o_attributes = ft_init_o_attributes();
	return (data);
}

void	ft_init_player(t_player *player)
{
	player->position[0] = NONE;
	player->position[1] = NONE;
	player->direction[0] = UNSET;
	player->direction[1] = UNSET;
	player->pov[0] = UNSET;
	player->pov[1] = UNSET;
	player->orientation = NONE;
}

t_map	*ft_init_map(t_data *data, char *file)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	if (map == NULL)
		ft_errno(MEM, data);
	map->file = NULL;
	map->fd = -1;
	map->floor.s_value = 0;
	map->floor.s_rgb.b = 0;
	map->floor.s_rgb.g = 0;
	map->floor.s_rgb.r = 0;
	map->texture_north = NULL;
	map->texture_south = NULL;
	map->texture_west = NULL;
	map->texture_east = NULL;
	map->ceiling.s_value = 0;
	map->ceiling.s_rgb.b = 0;
	map->ceiling.s_rgb.g = 0;
	map->ceiling.s_rgb.r = 0;
	ft_init_player(&map->player);
	map->x_size = 0;
	map->start = 0;
	map->file = file;
	return (map);
}
