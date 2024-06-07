/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelvign <gdelvign@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 09:49:38 by gdelvign          #+#    #+#             */
/*   Updated: 2023/10/25 14:09:48 by gdelvign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_is_lower(int c)
{
	if (c >= 97 && c <= 122)
		return (1);
	return (0);
}

static int	ft_is_upper(int c)
{
	if (c >= 65 && c <= 90)
		return (1);
	return (0);
}

int	ft_isalpha(int c)
{
	return (ft_is_upper(c) || ft_is_lower(c));
}
