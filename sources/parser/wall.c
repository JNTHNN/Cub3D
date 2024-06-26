/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgasparo <jgasparo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 11:21:52 by jgasparo          #+#    #+#             */
/*   Updated: 2024/06/26 11:44:10 by jgasparo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_check_walls(t_data *data)
{
	char	**map;
	int		x;

	x = 0;
	map = data->map->map;
	while (map[0][x] && map[0][++x])
	{
		// printf("le char est [%d][%d]\n", ft_wall(map[0][x], TOP), x);
		if (ft_wall(map[0][x], TOP))
				ft_errno(MAP_NOT_CLOSE, data);
	}
	printf("check\n");
}
