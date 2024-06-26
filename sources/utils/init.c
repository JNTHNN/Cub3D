/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgasparo <jgasparo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 20:37:00 by jgasparo          #+#    #+#             */
/*   Updated: 2024/06/26 10:41:20 by jgasparo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_info	*ft_init_info(t_data *data)
{
    t_info  *info;

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

t_data	*ft_init_data(char *file)
{
	t_data  *data;
	
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
	return (data);
}

t_map	*ft_init_map(t_data *data, char *file)
{
    t_map   *map;

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
	map->player.orientation = NONE;
    map->player.position[0] = -1;
    map->player.position[1] = -1;
	map->x_size = 0;
    map->start = 0;
    map->file = file;
    return (map);
}
