/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adda-sil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 19:01:44 by adda-sil          #+#    #+#             */
/*   Updated: 2019/07/21 23:01:14 by adda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "digits.h"

int		check_arg_nbr(char *nbr)
{
	while (*nbr)
		if (!(*nbr >= '0' && *nbr++ <= '9'))
			return (0);
	return (1);
}

char	*trim_zeros(char *str)
{
	int initial_len;
	int i;

	i = -1;
	initial_len = ft_strlen(str);
	while (str[++i] == '0')
		;
	if ((initial_len - i) < initial_len)
		return (str[i] == 0 ? "0" : &str[i]);
	return (str);
}

int		check_validity(char *buf)
{
	int i;

	i = 0;
	while (buf[i])
	{
		if (buf[i] < '0' || buf[i] > '9')
			return (0);
		while (buf[i] >= '0' && buf[i] <= '9')
			i++;
		while (buf[i] == ' ')
			i++;
		if (buf[i++] != ':')
			return (0);
		while (buf[i] == ' ')
			i++;
		if (buf[i] < ' ' || buf[i] > '~')
			return (0);
		while (buf[i] >= ' ' && buf[i] <= '~' && buf[i] != '\n')
			i++;
		if (buf[i] != '\n' && buf[i + 1] != '\0')
			return (0);
		while (buf[i] == '\n')
			i++;
	}
	return (i);
}

int		check_args(int ac, char **av)
{
	char *buffer;
	char *filename;

	filename = "./numbers.dict";
	if (ac > 3 || ac < 2)
	{
		ft_putstr("Error\n");
		return (0);
	}
	filename = (ac == 2 ? "./numbers.dict" : av[1]);
	g_arg_nbr = trim_zeros((ac == 3 ? av[2] : av[1]));
	if (!*g_arg_nbr || !check_arg_nbr(g_arg_nbr))
		return (ft_putstr("Error\n"));
	if (!((buffer = read_dict(filename))
				&& (check_validity(buffer))
				&& (parse_dict(buffer))))
	{
		free(buffer);
		return (ft_putstr("Dict Error\n"));
	}
	free(buffer);
	return (1);
}
