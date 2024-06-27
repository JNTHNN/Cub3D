/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgasparo <jgasparo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 21:55:52 by jgasparo          #+#    #+#             */
/*   Updated: 2024/06/26 10:18:30 by jgasparo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_setup_map(t_data *data)
{
	// maintenant ouverture de la map
	data->map->fd = open(data->map->file, O_RDONLY);
	if (data->map->fd == -1)
		ft_errno(ERR_FD, data);
	// commencons par les textures / couleurs
	ft_get_info(data);
	// maintenant on save la map
	ft_get_map(data);
	// on a la map, on va checker si elle est valide
	ft_check_map(data); // pensez a checker si mauvais char dans la map -> DONE ft_basic_check
	ft_check_player(data);
	
	
	
	ft_print_struct(data->map);
}
