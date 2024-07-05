/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelvign <gdelvign@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 11:55:36 by jgasparo          #+#    #+#             */
/*   Updated: 2024/07/05 22:31:27 by gdelvign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*ft_free_array(char **arr)
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
		if (info->floor)
			free(info->floor);
		if (info->ceiling)
			free(info->ceiling);
		if (info->texture_north)
			free(info->texture_north);
		if (info->texture_south)
			free(info->texture_south);
		if (info->texture_west)
			free(info->texture_west);
		if (info->texture_east)
			free(info->texture_east);
		free(info);
	}
}

void	ft_free_map(t_map *map)
{
	if (map)
	{
		// if (map->file)
		// 	free(map->file); argv[1]
		if (map->texture_north)
			free(map->texture_north);
		if (map->texture_south)
			free(map->texture_south);
		if (map->texture_west)
			free(map->texture_west);
		if (map->texture_east)
			free(map->texture_east);
		if (map->map)
			ft_free_array(map->map);
		if (map->square_map)
			ft_free_array(map->square_map);
		// if (map.player)
			// a voir si besoin
		free(map);
	}
}

void	ft_free_file(t_file *file)
{
	if (file)
	{
		if (file->raw_file)
			ft_free_array(file->raw_file);
		free(file);
	}
}

void	ft_free_data(t_data *data)
{
	if (data)
	{
		// voir pour les pointeurs mlx
		if (data->info)
			ft_free_info(data->info);
		if (data->img)
			free(data->img);
			// faire free_img
		if (data->map)
			ft_free_map(data->map);
		if (data->file)
			ft_free_file(data->file);
		free(data);
	}
}
// free tout la struct data