/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelvign <gdelvign@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 13:14:51 by gdelvign          #+#    #+#             */
/*   Updated: 2024/07/05 15:00:21 by gdelvign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICS_H
# define GRAPHICS_H

/* windows.c */
int					ft_on_keydown(int keycode, t_data *data);
int					ft_on_keyup(int keycode, t_data *data);
int					ft_on_mousemove(int x, int y, t_data *data);
int					ft_on_mousedown(int button, int x, int y, t_data *data);
int					ft_on_mouseup(int button, int x, int y, t_data *data);
int					ft_close_window(t_data *data);
int					ft_play(t_data *data);
void				ft_img_pix_put(t_img *img, int x, int y, int color);
void				ft_set_black(t_data *data);
int					ft_player_moving(t_data *data);

/*  init.c  */
t_orientation_att	ft_init_o_attributes(void);
void				ft_init_mlx(t_data *data);

/*  settings.c  */
int					ft_mlx_settings(t_data *data);

/* textures.c */
void				ft_set_textures(t_data *data);

/* blur.c */
void				ft_apply_blur(t_img *img, int radius);

#endif