/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgasparo <jgasparo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 23:51:00 by jgasparo          #+#    #+#             */
/*   Updated: 2024/07/09 15:50:05 by jgasparo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
**	Fills in texture info + removes the \n
*/
static void	ft_fill_info_texture(char *raw_texture, char **texture,
	t_data *data)
{
	char	*temp;

	temp = ft_strtrim(raw_texture + 2, " \t\n");
	if (!temp || !temp[0])
	{
		free(temp);
		ft_error(MISSING, STR_MISSING, data);
	}
	*texture = ft_strdup(temp);
	free(temp);
	if (!*texture)
		ft_error(MEM, STR_MEM, data);
}

/*
**	Obtains information for each type of texture
*/
void	ft_get_info_texture(t_data *data)
{
	ft_fill_info_texture(data->info->texture_north,
		&(data->map->texture_north), data);
	ft_fill_info_texture(data->info->texture_south,
		&(data->map->texture_south), data);
	ft_fill_info_texture(data->info->texture_west,
		&(data->map->texture_west), data);
	ft_fill_info_texture(data->info->texture_east,
		&(data->map->texture_east), data);
	if (data->info)
		ft_free_info(data->info);
}
