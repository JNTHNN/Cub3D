/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgasparo <jgasparo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 20:37:00 by jgasparo          #+#    #+#             */
/*   Updated: 2024/06/29 03:08:21 by jgasparo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_info	*ft_init_info(t_data *data)
{
    t_info  *info;

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

static u_color ft_init_color(void)
{
    u_color rgb;

    rgb.s_value = 0;
    rgb.s_rgb.b = 0;
    rgb.s_rgb.g = 0;
    rgb.s_rgb.r = 0;
    return (rgb);
}


static t_map	*ft_init_map(t_data *data, char *file)
{
    t_map   *map;

    map = (t_map *)malloc(sizeof(t_map));
    if (!map)
        ft_errno(MEM, data);
	map->file = NULL;
	map->fd = -1;
    map->floor = ft_init_color();
    map->ceiling = ft_init_color();
	map->texture_north = NULL;
    map->texture_south = NULL;
    map->texture_west = NULL;
    map->texture_east = NULL;
	map->player.orientation = NONE;
    map->player.position[0] = -1;
    map->player.position[1] = -1;
    map->y_size = 0;
	map->x_size = 0;
    map->file = file;
    map->map = NULL;
    map->square_map = NULL;
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

t_data	*ft_init_data(char *file)
{
	t_data  *data;
	
	data = (t_data *)malloc(sizeof(t_data));
    if (!data)
		ft_errno(MEM, data);
	data->mlx = NULL;
    data->win = NULL;
    data->img = (t_img *)malloc(sizeof(t_img));
    if (!data->img)
        ft_errno(MEM, data);
    data->img->mlx_img = NULL;
    data->img->addr = NULL;
    data->img->bpp = 0;
    data->img->line_len = 0;
    data->img->endian = 0;
	data->map = ft_init_map(data, file);
    data->info = ft_init_info(data);
    data->file = ft_init_file(data);
	return (data);
}
