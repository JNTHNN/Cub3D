/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelvign <gdelvign@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 11:27:17 by gdelvign          #+#    #+#             */
/*   Updated: 2024/07/08 17:19:29 by gdelvign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_nullify_ptrs(void *structure, size_t num_members, ...)
{
	size_t	i;
	void	**ptr;
	size_t	offset;
	va_list	members;

	va_start(members, num_members);
	i = -1;
	while (++i < num_members)
	{
		offset = va_arg(members, size_t);
		ptr = (void **)((char *)structure + offset);
		*ptr = NULL;
	}
	structure = NULL;
	va_end(members);
}
