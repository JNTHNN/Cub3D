/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelvign <gdelvign@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:15:41 by jgasparo          #+#    #+#             */
/*   Updated: 2024/06/21 12:27:12 by gdelvign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_get_info_texture(t_map *map, t_info *info)
{
	// texture
	char	**texture;
	
	texture = ft_split(info->texture_north, ' ');
	map->texture_north = ft_strdup(texture[1]);
	ft_memset(map->texture_north + (ft_strlen(map->texture_north) - 1), 0, 1); // remove le \n
	ft_free_array(texture);
	texture = ft_split(info->texture_south, ' ');
	map->texture_south = ft_strdup(texture[1]);
	ft_memset(map->texture_south + (ft_strlen(map->texture_south) - 1), 0, 1); // remove le \n
	ft_free_array(texture);
	texture = ft_split(info->texture_west, ' ');
	map->texture_west = ft_strdup(texture[1]);
	ft_memset(map->texture_west + (ft_strlen(map->texture_west) - 1), 0, 1); // remove le \n
	ft_free_array(texture);
	texture = ft_split(info->texture_east, ' ');
	map->texture_east = ft_strdup(texture[1]);
	ft_memset(map->texture_east + (ft_strlen(map->texture_east) - 1), 0, 1); // remove le \n
	ft_free_array(texture);
}

void	ft_init_info(t_info *info)
{
	info->floor = NULL;
	info->ceiling = NULL;
	info->texture_north = NULL;
	info->texture_south = NULL;
	info->texture_west = NULL;
	info->texture_east = NULL;
}

void	ft_check_data(char *line, t_info *info)
{
	if (!ft_strncmp(line, FLOOR, ft_strlen(FLOOR)))
	{
		if (!info->floor)
			info->floor = ft_strdup(line);
		else
			ft_errno(DUP_INFO, NULL); // ajouter map a clean
	}
	else if (!ft_strncmp(line, CEILING, ft_strlen(CEILING)))
	{
		if (!info->ceiling)
			info->ceiling = ft_strdup(line);
		else
			ft_errno(DUP_INFO, NULL); // ajouter map a clean
	}
	else if (!ft_strncmp(line, NORTH, ft_strlen(NORTH)))
	{
		if (!info->texture_north)
			info->texture_north = ft_strdup(line);
		else
			ft_errno(DUP_INFO, NULL); // ajouter map a clean
	}
	else if (!ft_strncmp(line, SOUTH, ft_strlen(SOUTH)))
	{
		if (!info->texture_south)
			info->texture_south = ft_strdup(line);
		else
			ft_errno(DUP_INFO, NULL); // ajouter map a clean
	}
	else if (!ft_strncmp(line, WEST, ft_strlen(WEST)))
	{
		if (!info->texture_west)
			info->texture_west = ft_strdup(line);
		else
			ft_errno(DUP_INFO, NULL); // ajouter map a clean
	}
	else if (!ft_strncmp(line, EAST, ft_strlen(EAST)))
	{
		if (!info->texture_east)
			info->texture_east = ft_strdup(line);
		else
			ft_errno(DUP_INFO, NULL); // ajouter map a clean
	}
}

void	ft_get_info(t_data *data)
{
	// recuperer la ligne commencant par l'id F dans le file pour avoir la couleur du sol
	// a voir si error si +de 2 lines F ?
	// pourquoi ne pas faire une struct ayant les données afin de savoir si elles sont toutes là ?
	char	*line;
	char	**rgb;
	t_info	info;
	
	// checker pour plusieurs lignes -> increment un flag et si >1 == error
	// si 1 data de info not init -> error
	ft_init_info(&info);
	while (data->map.fd)
	{
		line = get_next_line(data->map.fd);
		if (!line || !ft_strncmp(line, "1", ft_strlen(line)))
			break ;
		ft_check_data(line, &info);
		free(line);
	}
	// checker si toutes les data de info sont init sinon error
	if (info.floor || info.ceiling)
	{
		// si ligne -> split pour avoir les 3 valeurs rgb / error si plus ?
		// printf("FLOOR [%s]\nCEILING [%s]\n", info.floor, info.ceiling);
		// printf("TEXTURE NORTH [%s] SOUTH [%s]\nWEST [%s] EAST [%s]\n", info.texture_north, info.texture_south, info.texture_west, info.texture_east);
		// setup les split pour chaque data
		// floor
		rgb = ft_split(info.floor, ',');
		if (!rgb || ft_arrlen(rgb) != 3)
			ft_errno(ERR_COLOR, data);
		for(int j = 0 ; rgb[j]; j++)
			printf("[%i] [%s]\n", j, rgb[j]);
		data->map.floor.s_rgb.r = ft_atoi(rgb[0] + 1);
		data->map.floor.s_rgb.g = ft_atoi(rgb[1]);
		data->map.floor.s_rgb.b = ft_atoi(rgb[2]);
		// checker les datas -> error | soit refaire un atoi qui va introduire les datas suivant le flag (R|G|B) + nombre compris entre 0 et 255
		ft_free_array(rgb);
		// ceiling
		rgb = ft_split(info.ceiling, ',');
		if (!rgb || ft_arrlen(rgb) != 3)
			ft_errno(ERR_COLOR, data);
		for(int j = 0 ; rgb[j]; j++)
			printf("[%i] [%s]\n", j, rgb[j]);
		data->map.ceiling.s_rgb.r = ft_atoi(rgb[0] + 1);
		data->map.ceiling.s_rgb.g = ft_atoi(rgb[1]);
		data->map.ceiling.s_rgb.b = ft_atoi(rgb[2]);
		ft_free_array(rgb);
	}
	ft_get_info_texture(&data->map, &info);
	free(line);
	// printf("la line sol color = [%s]\n", line);
}