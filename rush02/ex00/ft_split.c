/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adda-sil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 08:05:27 by adda-sil          #+#    #+#             */
/*   Updated: 2019/07/21 16:46:31 by adda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "digits.h"

char	*ft_strstr(char *str, char *to_find)
{
	int i;
	int j;

	if (!*to_find)
		return (str);
	i = 0;
	while (str[i])
	{
		j = 0;
		while (to_find[j])
		{
			if (to_find[j] == str[i])
				return (&str[i]);
			j++;
		}
		i++;
	}
	return (0);
}

int		ft_str_occurence(char *str, char *charset, int charset_len)
{
	char	*end;
	int		len;
	int		count;

	count = 0;
	while (*charset && (end = ft_strstr(str, charset)))
	{
		len = end - str;
		if (len > 0)
			count++;
		str = end + charset_len;
	}
	if (ft_strlen(str))
		count++;
	return (count);
}

int		alloc_str(char **res, int i, char *str, int len)
{
	int j;

	j = -1;
	res[i] = malloc(sizeof(char) * len + 1);
	while (++j < len)
		res[i][j] = str[j];
	res[i][j] = '\0';
	return (len);
}

char	**ft_split(char *str, char *charset)
{
	char	*ptr_end;
	char	**res;
	int		len;
	int		str_len;
	int		i;

	i = -1;
	len = ft_str_occurence(str, charset, 1);
	res = malloc(sizeof(char *) * (len) + 1);
	if (len > 0 && *charset)
	{
		while ((ptr_end = ft_strstr(str, charset)))
			if ((str_len = ptr_end - str) > 0)
				str += alloc_str(res, ++i, str, str_len) + 1;
			else
				str += 1;
	}
	if (len > 0 && ft_strlen(str))
		alloc_str(res, ++i, str, ft_strlen(str));
	res[i + 1] = 0;
	return (res);
}
