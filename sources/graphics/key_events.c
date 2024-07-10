/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgasparo <jgasparo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 13:09:13 by gdelvign          #+#    #+#             */
/*   Updated: 2024/07/10 12:02:53 by jgasparo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_on_keydown(int keycode, t_data *data)
{
	t_player	*player;

	player = &data->map->player;
	if (keycode == ESC)
		ft_close_window(data);
	else if (keycode == KEY_UP)
		player->move |= M_UP;
	else if (keycode == KEY_DOWN)
		player->move |= M_DOWN;
	else if (keycode == KEY_LEFT)
		player->move |= M_LEFT;
	else if (keycode == KEY_RIGHT)
		player->move |= M_RIGHT;
	else if (keycode == ARROW_LEFT)
		player->move |= M_ROTATE_LEFT;
	else if (keycode == ARROW_RIGHT)
		player->move |= M_ROTATE_RIGHT;
	return (EXIT_SUCCESS);
}

int	ft_on_keyup(int keycode, t_data *data)
{
	t_player	*player;

	player = &data->map->player;
	if (keycode == ESC)
		ft_close_window(data);
	else if (keycode == KEY_UP)
		player->move &= ~M_UP;
	else if (keycode == KEY_DOWN)
		player->move &= ~M_DOWN;
	else if (keycode == KEY_LEFT)
		player->move &= ~M_LEFT;
	else if (keycode == KEY_RIGHT)
		player->move &= ~M_RIGHT;
	else if (keycode == ARROW_LEFT)
		player->move &= ~M_ROTATE_LEFT;
	else if (keycode == ARROW_RIGHT)
		player->move &= ~M_ROTATE_RIGHT;
	return (EXIT_SUCCESS);
}
