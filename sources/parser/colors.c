/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgasparo <jgasparo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 23:29:43 by jgasparo          #+#    #+#             */
/*   Updated: 2024/06/25 23:31:21 by jgasparo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_fill_rgb(char *color, u_color *rgb, t_data *data)
{
	char	**rgb_values;
	int		flag;

	flag = 0;
	rgb_values = ft_split(color, ',');
	if (!rgb_values || ft_arrlen(rgb_values) != 3)
		ft_errno(ERR_COLOR, data);
	rgb->s_rgb.r = ft_atoi_color(rgb_values[0] + 1, &flag);
	if (flag)
		ft_errno(NOT_NB, data);
	rgb->s_rgb.g = ft_atoi_color(rgb_values[1], &flag);
	if (flag)
		ft_errno(NOT_NB, data);
	rgb->s_rgb.b = ft_atoi_color(rgb_values[2], &flag);
	if (flag)
		ft_errno(NOT_NB, data);
	ft_free_array(rgb_values);

}

void	ft_fill_color(t_data *data)
{
	ft_fill_rgb(data->info->floor, &(data->map->floor), data);
	ft_fill_rgb(data->info->ceiling, &(data->map->ceiling), data);
}
