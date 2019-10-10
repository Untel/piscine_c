/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adda-sil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 17:35:06 by adda-sil          #+#    #+#             */
/*   Updated: 2019/07/15 19:14:27 by adda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*ptr;
	char	*mal;
	int		size;

	ptr = src;
	while (*ptr)
		ptr++;
	size = (int)(ptr - src) + 1;
	mal = malloc(sizeof(char) * (size));
	while (*src)
		*mal++ = *src++;
	*mal++ = 0;
	return (mal - size);
}
