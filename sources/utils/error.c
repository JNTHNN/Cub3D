/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelvign <gdelvign@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 14:50:35 by jgasparo          #+#    #+#             */
/*   Updated: 2024/07/05 14:55:07 by gdelvign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_error(int code, char *err_msg, t_data *data)
{
	ft_putendl_fd(err_msg, STDERR_FILENO);
	if (data)
		ft_free_data(data);
	exit(code);
}
