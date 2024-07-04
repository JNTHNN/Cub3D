/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelvign <gdelvign@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 22:09:31 by jgasparo          #+#    #+#             */
/*   Updated: 2024/07/04 17:08:26 by gdelvign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		ft_errno(MLX, data);
	data->win = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, TITLE);
	if (data->win == NULL)
		ft_errno(WIN, data);
	ft_set_textures(data);
}
