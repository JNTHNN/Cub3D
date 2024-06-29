/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgasparo <jgasparo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 13:14:51 by gdelvign          #+#    #+#             */
/*   Updated: 2024/06/25 22:19:52 by jgasparo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICS_H
# define GRAPHICS_H

int	    ft_handle_key_events(int keycode, t_data *data);
int	    ft_handle_mouse_events(int button, int x, int y, t_data *data);
int	    ft_close_window(t_data *data);
int	    ft_play(t_data *data);

/*  init.c  */
void	ft_init_mlx(t_data *data);

/*  settings.c  */
int     ft_mlx_settings(t_data *data);

#endif