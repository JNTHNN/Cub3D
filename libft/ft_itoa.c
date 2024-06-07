/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelvign <gdelvign@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 13:43:27 by gdelvign          #+#    #+#             */
/*   Updated: 2024/01/16 10:23:11 by gdelvign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_numlen(int nb)
{
	size_t	nb_len;

	nb_len = 0;
	while (nb > 0)
	{
		nb_len++;
		nb /= 10;
	}
	return (nb_len);
}

static char	*ft_malloc(size_t len)
{
	char	*str;

	str = (char *)malloc((len) * sizeof(char));
	if (!str)
		return (NULL);
	return (str);
}

static char	*ft_fillstr(char *str, size_t len, int nb)
{
	str[len - 1] = '\0';
	if (nb < 0)
	{
		while (nb)
		{
			len--;
			str[len - 1] = ((nb % 10) * -1) + '0';
			nb /= 10;
		}
		str[0] = '-';
	}
	else
	{
		while (nb)
		{
			len--;
			str[len - 1] = (nb % 10) + '0';
			nb /= 10;
		}
	}
	return (str);
}

static char	*ft_itoa_negative(int n)
{
	char	*nb_str;
	size_t	str_len;

	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	str_len = ft_numlen(-n) + 2;
	nb_str = ft_malloc(str_len);
	if (!nb_str)
		return (NULL);
	ft_fillstr(nb_str, str_len, n);
	return (nb_str);
}

char	*ft_itoa(int n)
{
	char	*nb_str;
	size_t	str_len;

	nb_str = NULL;
	if (n < 0)
	{
		return (ft_itoa_negative(n));
	}
	else if (n == 0)
		return (ft_strdup("0"));
	else
	{
		str_len = ft_numlen(n) + 1;
		nb_str = ft_malloc(str_len);
		if (!nb_str)
			return (NULL);
		ft_fillstr(nb_str, str_len, n);
	}
	return (nb_str);
}
