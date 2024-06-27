/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelvign <gdelvign@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 13:09:13 by gdelvign          #+#    #+#             */
/*   Updated: 2024/06/26 12:01:24 by gdelvign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* Handles key press events */
int	ft_handle_key_events(int keycode, t_data *data)
{
	if (keycode == ESC)
		ft_close_window(data);
	return (EXIT_SUCCESS);
}

/* Handles mouse events */
int	ft_handle_mouse_events(int button, int x, int y, t_data *data)
{
	// dumb code to silence compilation warnings
	(void)x;
	(void)y;
	if (data && button == 5)
		return (5);
	return (EXIT_SUCCESS);
}
