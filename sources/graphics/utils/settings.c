/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelvign <gdelvign@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 22:10:03 by jgasparo          #+#    #+#             */
/*   Updated: 2024/07/01 15:10:57 by gdelvign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_mlx_settings(t_data *data)
{
	mlx_hook(data->win, ON_KEYDOWN, 0, ft_handle_keydown_events, data);
	mlx_hook(data->win, ON_KEYUP, 0, ft_handle_keyup_events, data);
	mlx_hook(data->win, ON_MOUSEDOWN, 0, ft_handle_mouse_events, data);
	mlx_hook(data->win, ON_DESTROY, 0, ft_close_window, data);
	if (mlx_loop_hook(data->mlx, &ft_play, data))
		return (ft_close_window(data));
	mlx_loop(data->mlx);
	return (EXIT_SUCCESS);
}
