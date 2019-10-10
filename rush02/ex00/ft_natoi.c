/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adda-sil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 17:37:30 by adda-sil          #+#    #+#             */
/*   Updated: 2019/07/21 20:49:02 by adda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "digits.h"

int	is_num(char c)
{
	return (c >= '0' && c <= '9');
}

int	ft_natoi(char *str, int n)
{
	int				i;
	unsigned int	count;

	i = -1;
	count = 0;
	while (is_num(str[++i]) && i < n)
		count = count * 10 + (str[i] - '0');
	return (count);
}
