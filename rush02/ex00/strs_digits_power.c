/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strs_digits_power.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adda-sil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 18:52:52 by adda-sil          #+#    #+#             */
/*   Updated: 2019/07/21 21:38:25 by adda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <digits.h>

char	*print_powered_digits(int *tab, int tab_len)
{
	int		i;
	int		j;
	int		len;
	char	**ptr;
	char	*final_str;

	len = tab_len + (tab_len - 1);
	ptr = malloc(sizeof(char *) * len + 1);
	i = -1;
	j = 0;
	if (len == 1 && tab[0] == 0)
		return (get_litteral(tab[++i]));
	while (++i < tab_len)
	{
		if (tab[i] != 0)
			ptr[j++] = digits_to_litteral(tab[i]);
		if (!tab[i] && (i > g_power_length && ((i % g_power_length - 1) == 0)))
			ptr[j++] = g_powers[g_power_length - 1];
		else if (i != tab_len - 1 && (tab[i] != 0))
			ptr[j++] = g_powers[((tab_len - i - 2) % (g_power_length))];
	}
	ptr[j] = 0;
	final_str = ft_strjoin(j, ptr, " ");
	free(ptr);
	return (final_str);
}
