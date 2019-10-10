/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adda-sil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 15:16:27 by adda-sil          #+#    #+#             */
/*   Updated: 2019/07/18 16:38:52 by adda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int					ft_strlen(char *str)
{
	int i;

	i = -1;
	while (str[++i] != '\0')
		;
	return (i);
}

char				*ft_strdup(char *src)
{
	char	*ptr;
	char	*mal;

	ptr = src;
	while (*ptr)
		ptr++;
	if (!(mal = malloc(sizeof(char) * (ptr - src) + 1)))
		return (0);
	ptr = mal;
	while (*src)
		*mal++ = *src++;
	*mal++ = 0;
	return (ptr);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	struct s_stock_str	*stock;
	int					i;

	stock = NULL;
	if (ac < 0)
		return (stock);
	if (!(stock = malloc(sizeof(t_stock_str) * (ac + 1))))
		return ((stock = NULL));
	i = -1;
	while (++i < ac)
	{
		stock[i].size = ft_strlen(av[i]);
		stock[i].str = av[i];
		if (!(stock[i].copy = ft_strdup(av[i])))
			return ((stock = NULL));
	}
	stock[i].str = 0;
	return (stock);
}
