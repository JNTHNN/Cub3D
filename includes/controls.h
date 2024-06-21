/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelvign <gdelvign@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 13:14:51 by gdelvign          #+#    #+#             */
/*   Updated: 2024/06/21 14:37:42 by gdelvign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTROLS_H
# define CONTROLS_H

int	ft_handle_key_events(int keycode, t_data *data);
int	ft_handle_mouse_events(int button, int x, int y, t_data *data);
int	ft_close_window(t_data *data);
int	ft_play(t_data *data);

#endif