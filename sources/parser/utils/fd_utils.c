/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelvign <gdelvign@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 14:49:53 by jgasparo          #+#    #+#             */
/*   Updated: 2024/07/04 21:12:10 by gdelvign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
**  Opens the file into file descriptor
*/
void	ft_open_fd(t_data *data)
{
	data->file->fd = open(data->map->file, O_RDONLY);
	if (data->file->fd == -1)
		ft_errno(ERR_FD, data);
}

/*
**  Close the file descriptor
*/
void	ft_close_fd(t_data *data)
{
	if (close(data->file->fd) == -1)
		ft_errno(ERR_FD, data);
	data->file->fd = -1;
}
