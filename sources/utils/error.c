/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelvign <gdelvign@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 14:50:35 by jgasparo          #+#    #+#             */
/*   Updated: 2024/07/03 14:38:47 by gdelvign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void ft_print_mlx_error(int err_code)
{
	if (err_code == MLX)
		ft_putendl_fd(STR_ERR_MLX, STDERR_FILENO);
	else if (err_code == WIN)
		ft_putendl_fd(STR_ERR_WIN, STDERR_FILENO);
	else if (err_code == IMG)
		ft_putendl_fd(STR_ERR_IMG, STDERR_FILENO);
	else if (err_code == ADD)
		ft_putendl_fd(STR_ERR_ADD, STDERR_FILENO);
}

static void	ft_print_error(int err_code)
{
	if (err_code <= MLX)
		ft_print_mlx_error(err_code);
	else if (err_code == MEM)
		ft_putendl_fd(STR_MEM, STDERR_FILENO);
	else if (err_code == TOO_MANY)
		ft_putendl_fd(STR_TOO_MANY, STDERR_FILENO);
	else if (err_code == NO_MAP)
		ft_putendl_fd(STR_NO_MAP, STDERR_FILENO);
	else if (err_code == WRONG_EXT)
		ft_putendl_fd(STR_WRONG_EXT, STDERR_FILENO);
	else if (err_code == ERR_FD)
		perror("Error\n");
	else if (err_code == DUP_INFO)
		ft_putendl_fd(STR_DUP_INFO, STDERR_FILENO);
	else if (err_code == ERR_COLOR)
		ft_putendl_fd(STR_ERR_COLOR, STDERR_FILENO);
	else if (err_code == MISSING)
		ft_putendl_fd(STR_MISSING, STDERR_FILENO);
	else if (err_code == NOT_NB)
		ft_putendl_fd(STR_NOT_NB, STDERR_FILENO);
	else if (err_code == NO_MAP_CONTENT)
		ft_putendl_fd(STR_NO_MAP_CONTENT, STDERR_FILENO);
	else if (err_code == MAP_NOT_CLOSE)
		ft_putendl_fd(STR_MAP_NOT_CLOSE, STDERR_FILENO);
	else if (err_code == NO_PLAYER)
		ft_putendl_fd(STR_NO_PLAYER, STDERR_FILENO);
	else if (err_code == MANY_PLAYERS)
		ft_putendl_fd(STR_MANY_PLAYERS, STDERR_FILENO);
	else if (err_code == WRONG_CHAR)
		ft_putendl_fd(STR_WRONG_CHAR, STDERR_FILENO);
	else if (err_code == AMB_PLAYER)
		ft_putendl_fd(STR_AMB_PLAYER, STDERR_FILENO);
}

void	ft_errno(int err_code, t_data *data)
{
	ft_print_error(err_code);
	if (data)
		ft_free_data(data);
	exit(err_code); // EXIT_FAILURE 
}