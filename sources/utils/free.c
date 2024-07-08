/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelvign <gdelvign@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 11:55:36 by jgasparo          #+#    #+#             */
/*   Updated: 2024/07/08 12:37:24 by gdelvign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*ft_free_array(void **arr)
{
	int	i;

	i = -1;
	if (arr)
	{
		while (arr[++i])
		{
			free(arr[i]);
			arr[i] = NULL;
		}
		free(arr);
		arr = NULL;
	}
	return (NULL);
}

void	ft_free_info(t_info *info)
{
	if (info)
	{

		if (info && info->floor)
			free(info->floor);
			printf("%p\n", info->floor);
		// if (info->ceiling)
		// 	free(info->ceiling);
		// if (info->texture_north)
		// 	free(info->texture_north);
		// if (info->texture_south)
		// 	free(info->texture_south);
		// if (info->texture_west)
		// 	free(info->texture_west);
		// if (info->texture_east)
		// 	free(info->texture_east);
		free(info);
		info = NULL;
	}
	// ft_nullify_ptrs(&info, 6, offsetof(t_info, floor), offsetof(t_info, ceiling),
	// 	offsetof(t_info, texture_north), offsetof(t_info, texture_south),
	// 	offsetof(t_info, texture_west), offsetof(t_info, texture_east));
}

void	ft_free_map(t_map *map)
{
	if (map)
	{
		if (map->file)
			free(map->file);
		if (map->texture_north)
			free(map->texture_north);
		if (map->texture_south)
			free(map->texture_south);
		if (map->texture_west)
			free(map->texture_west);
		if (map->texture_east)
			free(map->texture_east);
		if (map->map)
			ft_free_array((void **)map->map);
		if (map->square_map)
			ft_free_array((void **)map->square_map);
		free(map);
	}
}

void	ft_free_file(t_file *file)
{
	if (file)
	{
		if (file->raw_file)
			ft_free_array((void **)file->raw_file);
		free(file);
	}
}

void	ft_free_data(t_data *data)
{
	if (data)
	{
		if (data->mlx)
			free(data->mlx);
		if (data->img && data->img->mlx_img)
			mlx_destroy_image(data->mlx, data->img->mlx_img);
		if (data->win)
			mlx_destroy_window(data->mlx, data->win);
		if (data->info)
			ft_free_info(data->info);
		if (data->map)
			ft_free_map(data->map);
		if (data->mtx)
			ft_free_array((void **)data->mtx);
		if (data->file)
			ft_free_file(data->file);
		free(data);
	}
}
