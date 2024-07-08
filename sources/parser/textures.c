/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelvign <gdelvign@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 23:51:00 by jgasparo          #+#    #+#             */
/*   Updated: 2024/07/08 11:11:43 by gdelvign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
**	Fills in texture info + removes the \n
*/
static void	ft_fill_info_texture(char *raw_texture, char **texture)
{
	char	**texture_path;

	texture_path = ft_split(raw_texture, ' ');
	*texture = ft_strdup(texture_path[1]);
	ft_memset(*texture + (ft_strlen(*texture) - 1), 0, 1);
	ft_free_array((void **)texture_path);
}

/*
**	Obtains information for each type of texture
*/
void	ft_get_info_texture(t_data *data)
{
	ft_fill_info_texture(data->info->texture_north,
		&(data->map->texture_north));
	ft_fill_info_texture(data->info->texture_south,
		&(data->map->texture_south));
	ft_fill_info_texture(data->info->texture_west, &(data->map->texture_west));
	ft_fill_info_texture(data->info->texture_east, &(data->map->texture_east));
}
