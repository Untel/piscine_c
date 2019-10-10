/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adda-sil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 12:44:07 by adda-sil          #+#    #+#             */
/*   Updated: 2019/07/21 23:11:21 by adda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "digits.h"

void	free_all(void *str, void *tab)
{
	free(tab);
	free(str);
	free(g_powers);
	free(g_values);
	free(g_strings);
}

int		main(int ac, char **av)
{
	int		len;
	int		*tab;
	int		tab_len;
	char	*str;

	if (!(check_args(ac, av)))
		return (0);
	len = ft_strlen(g_arg_nbr);
	tab_len = (len / 3) + (len % 3 ? 1 : 0);
	tab = char_to_3digits_tabs(g_arg_nbr, len, tab_len);
	str = print_powered_digits(tab, tab_len);
	ft_putstr(str);
	free_all(str, tab);
	write(1, "\n", 1);
	return (0);
}
