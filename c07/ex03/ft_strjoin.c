/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adda-sil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 22:12:16 by adda-sil          #+#    #+#             */
/*   Updated: 2019/07/15 22:00:10 by adda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int i;

	i = -1;
	while (str[++i])
		;
	return (i);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*res;
	int		i;
	int		j;
	int		len;

	len = ((size > 0 ? size - 1 : 0) * ft_strlen(sep)) + 1;
	i = -1;
	while (++i < size)
		len += ft_strlen(strs[i]);
	res = malloc(sizeof(char) * len);
	i = -1;
	while (++i < size)
	{
		while (*strs[i])
			*res++ = *strs[i]++;
		j = -1;
		if (i != size - 1)
			while (sep[++j])
				*res++ = sep[j];
	}
	*res++ = 0;
	return (res - len);
}
