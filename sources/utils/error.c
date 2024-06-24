/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgasparo <jgasparo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 14:50:35 by jgasparo          #+#    #+#             */
/*   Updated: 2024/06/24 15:43:03 by jgasparo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_check_arg(int argc, char **argv)
{
	char	*file_extension;

	if (argc > 2)
		ft_errno(TOO_MANY, NULL);
	else if (argc < 2)
		ft_errno(NO_MAP, NULL);
	else
	{
		file_extension = ft_strrchr(MAP, DOT);
		if (!file_extension
			|| (ft_strlen(file_extension) != 4
				|| ft_strncmp(file_extension, CUB, ft_strlen(CUB))))
			ft_errno(WRONG_EXT, NULL);
		else
			printf("good = %s\n", file_extension);
	}
}

static void	ft_print_error(int err_code)
{
	if (err_code == MEM)
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
	else if (err_code == MLX)
		ft_putendl_fd(STR_ERR_MLX, STDERR_FILENO);
	else if (err_code == WIN)
		ft_putendl_fd(STR_ERR_WIN, STDERR_FILENO);
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
}

void	ft_errno(int err_code, t_data *data)
{
	ft_print_error(err_code);
	if (data)
		free(data);
	exit(err_code); // EXIT_FAILURE 
}