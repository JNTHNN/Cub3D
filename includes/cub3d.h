/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelvign <gdelvign@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 14:09:52 by jgasparo          #+#    #+#             */
/*   Updated: 2024/06/26 11:39:00 by gdelvign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdbool.h>
# include <fcntl.h>
# include "../minilibx/mlx.h"
# include "../libft/libft.h"
# include "typedef.h"
# include "error.h"
# include "utils.h"
# include "graphics.h"
# include "parser.h"
# include "graphics.h"

# define FLOOR "F "
# define CEILING "C "
# define NORTH "NO "
# define SOUTH "SO "
# define WEST "WE "
# define EAST "EA "
# define NO 1
# define SO 2
# define WE 3
# define EA 4

void	ft_errno(int err_code, t_data *data);

#endif