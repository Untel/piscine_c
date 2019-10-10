/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_to_3digits_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adda-sil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 13:45:09 by adda-sil          #+#    #+#             */
/*   Updated: 2019/07/21 21:31:04 by adda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "digits.h"

int		number_length(int nbr)
{
	if (nbr > 0)
		return (1 + (number_length(nbr / 10)));
	else
		return (0);
}

char	*get_litteral(int number)
{
	int i;

	i = -1;
	while (++i < g_length)
		if (g_values[i] == number)
			return (g_strings[i]);
	return (0);
}

int		words_count(int number)
{
	int count;

	count = 0;
	if (number / 100)
		count += 2;
	if (number % 100)
	{
		if ((get_litteral(number % 100)))
			count += 1;
		else
			count += 2;
	}
	return (count);
}

char	*digits_to_litteral(int number)
{
	char	**tab;
	char	*res;
	int		i;

	i = 0;
	tab = malloc(sizeof(char *) * words_count(number));
	if (number / 100)
	{
		tab[i++] = get_litteral(number / 100);
		tab[i++] = get_litteral(100);
	}
	if (number % 100)
	{
		if ((tab[i] = get_litteral(number % 100)))
			i++;
		else
		{
			tab[i++] = get_litteral(((number % 100) / 10) * 10);
			if ((number % 100) % 10 != 0 && i != 0)
				tab[i++] = get_litteral((number % 100) % 10);
		}
	}
	res = ft_strjoin(i, tab, " ");
	free(tab);
	return (res);
}

int		*char_to_3digits_tabs(char *str, int len, int tab_len)
{
	int		*tab;
	int		count;
	int		i;
	char	*cursor;

	tab = malloc(sizeof(int) * (tab_len));
	count = 0;
	i = 0;
	cursor = str + len;
	if (len % 3)
	{
		tab[i++] = ft_natoi(str, len % 3);
		str += (len % 3);
	}
	while (i < tab_len)
	{
		tab[i] = ft_natoi(str, 3);
		i++;
		str += 3;
	}
	return (tab);
}
