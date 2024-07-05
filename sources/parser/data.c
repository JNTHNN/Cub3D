/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelvign <gdelvign@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:15:41 by jgasparo          #+#    #+#             */
/*   Updated: 2024/07/05 12:50:06 by gdelvign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
**	Fills in the data and checks if it already exists
*/
static void	ft_fill_data(char **type, char *line, int *flag, t_data *data)
{
	if (!*type)
		*type = ft_strdup(line);
	else
		ft_error(DUP_INFO, STR_DUP_INFO, data);
	(*flag)++;
}

/*
**	Checks that the data corresponds to what we need
*/
void	ft_check_data(char *line, t_data *data, int *flag)
{
	t_info	*info;

	info = data->info;
	if (!ft_strncmp(line, FLOOR, ft_strlen(FLOOR)))
		ft_fill_data(&(info->floor), line, flag, data);
	else if (!ft_strncmp(line, CEILING, ft_strlen(CEILING)))
		ft_fill_data(&(info->ceiling), line, flag, data);
	else if (!ft_strncmp(line, NORTH, ft_strlen(NORTH)))
		ft_fill_data(&(info->texture_north), line, flag, data);
	else if (!ft_strncmp(line, SOUTH, ft_strlen(SOUTH)))
		ft_fill_data(&(info->texture_south), line, flag, data);
	else if (!ft_strncmp(line, WEST, ft_strlen(WEST)))
		ft_fill_data(&(info->texture_west), line, flag, data);
	else if (!ft_strncmp(line, EAST, ft_strlen(EAST)))
		ft_fill_data(&(info->texture_east), line, flag, data);
}
