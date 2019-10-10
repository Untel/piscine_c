/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adda-sil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 02:21:21 by adda-sil          #+#    #+#             */
/*   Updated: 2019/07/24 20:27:32 by mchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		is_num(char c)
{
	return (c >= '0' && c <= '9');
}

int		ft_natoi(char *str, int n)
{
	int				i;
	unsigned int	count;

	i = -1;
	count = 0;
	while (is_num(str[++i]) && i < n)
		count = count * 10 + (str[i] - '0');
	return (count);
}

int		ft_strlen(char *str)
{
	char	*ptr;

	ptr = str;
	while (*ptr++)
		;
	return (ptr - str);
}

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char			*dest_ptr;
	unsigned int	i;

	dest_ptr = dest;
	i = 0;
	while (*dest)
		dest++;
	while (i < nb && (*dest++ = *src++))
		i++;
	if (src[-1])
		*dest++ = '\0';
	return (dest_ptr);
}
