/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelvign <gdelvign@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 11:27:17 by gdelvign          #+#    #+#             */
/*   Updated: 2024/07/09 07:58:29 by gdelvign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_free_int_array(int **arr, int y)
{
	int	i;

	i = -1;
	while (++i < y)
	{
		if (arr[i])
		{
			free(arr[i]);
			arr[i] = NULL;
		}
	}
	free(arr);
	arr = NULL;
}

void	ft_free_minimap(t_data *data)
{
	if (data->minimap->img && data->minimap->img->mlx_img)
		mlx_destroy_image(data->mlx, data->minimap->img->mlx_img);
	free(data->minimap);
}

void	ft_free_textures(t_data *data)
{
	if (data->textures->tex_north)
	{
		if (data->textures->tex_north->img)
			mlx_destroy_image(data->mlx, data->textures->tex_north->img);
		free(data->textures->tex_north);
	}
	if (data->textures->tex_south)
	{
		if (data->textures->tex_south->img)
			mlx_destroy_image(data->mlx, data->textures->tex_south->img);
		free(data->textures->tex_south);
	}
	if (data->textures->tex_west)
	{
		if (data->textures->tex_west->img)
			mlx_destroy_image(data->mlx, data->textures->tex_west->img);
		free(data->textures->tex_west);
	}
	if (data->textures->tex_east)
	{
		if (data->textures->tex_east->img)
			mlx_destroy_image(data->mlx, data->textures->tex_east->img);
		free(data->textures->tex_east);
	}
	free(data->textures);
}
