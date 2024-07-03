/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelvign <gdelvign@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 20:37:00 by jgasparo          #+#    #+#             */
/*   Updated: 2024/07/03 15:34:08 by gdelvign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_info	*ft_init_info(t_data *data)
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

t_orientation_att	ft_init_o_attributes(void)
{
	t_orientation_att	attributes;

	attributes.north.dir[X] = 0;
	attributes.north.dir[Y] = -1;
	attributes.north.pov[X] = 0.66;
	attributes.north.pov[Y] = 0;
	attributes.south.dir[X] = 0;
	attributes.south.dir[Y] = 1;
	attributes.south.pov[X] = -0.66;
	attributes.south.pov[Y] = 0;
	attributes.east.dir[X] = 1;
	attributes.east.dir[Y] = 0;
	attributes.east.pov[X] = 0;
	attributes.east.pov[Y] = 0.66;
	attributes.west.dir[X] = -1;
	attributes.west.dir[Y] = 0;
	attributes.west.pov[X] = 0;
	attributes.west.pov[Y] = -0.66;
	return (attributes);
}

static u_color ft_init_color(void)
{
    u_color rgb;

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
	player->pov[0] = UNSET;
	player->pov[1] = UNSET;
	player->orientation = NONE;
	player->move = 0U;
}

static t_map	*ft_init_map(t_data *data, char *file)
{
    t_map   *map;

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
	data->o_attributes = ft_init_o_attributes();
    return (map);
}

static t_file  *ft_init_file(t_data *data)
{
    t_file  *file;

    file = (t_file *)malloc(sizeof(t_file));
    if (!file)
        ft_errno(MEM, data);
    file->raw_file = NULL;
    file->fd = -1;
    file->size = 0;
    file->start = 0;
    return (file);
}

static t_xpm	*ft_init_tex_data(t_data *data)
{
	t_xpm	*xpm;
	
	xpm = (t_xpm *)malloc(sizeof(t_xpm));
	if (!xpm)
		ft_errno(MEM, data);
	xpm = ft_memset(xpm, 0, sizeof(t_xpm));
	return (xpm);
}


static t_textures	*ft_init_textures(t_data *data)
{
	t_textures	*textures;

	textures = (t_textures *)malloc(sizeof(t_textures));
	if (!textures)
		ft_errno(MEM, data);
	textures->tex_north = ft_init_tex_data(data);
	textures->tex_south = ft_init_tex_data(data);
	textures->tex_east = ft_init_tex_data(data);
	textures->tex_west = ft_init_tex_data(data);
	textures->sprite = ft_init_tex_data(data); 
	return (textures);
}

t_data	*ft_init_data(char *file)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
    if (!data)
		ft_errno(MEM, data);
	data->mlx = NULL;
    data->win = NULL;
    data->img = (t_img *)malloc(sizeof(t_img));
    if (!data->img)
        ft_errno(MEM, data);
    data->img = ft_memset(data->img, 0, sizeof(t_img));
	data->map = ft_init_map(data, file);
    data->info = ft_init_info(data);
    data->file = ft_init_file(data);
	data->textures = ft_init_textures(data);
	return (data);
}
