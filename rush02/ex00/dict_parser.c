/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adda-sil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 15:20:02 by adda-sil          #+#    #+#             */
/*   Updated: 2019/07/21 23:10:06 by adda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "digits.h"

int		get_file_length(char *filename)
{
	int		fd;
	int		i;
	char	init_buffer[1];

	i = 0;
	if ((fd = open(filename, O_RDONLY)) == -1)
		return (0);
	while (read(fd, init_buffer, 1))
		i++;
	if (close(fd) == -1)
		return (0);
	return (i);
}

char	*read_dict(char *filename)
{
	int		len;
	char	*buffer;
	int		fd;

	if (!(len = get_file_length(filename)))
		return (0);
	buffer = malloc(sizeof(char) * (len + 1));
	if ((fd = open(filename, O_RDONLY)) == -1)
		return (0);
	read(fd, buffer, len + 1);
	buffer[len] = 0;
	if (close(fd) == -1)
		return (0);
	return (buffer);
}

int		is_power_pattern(char *str)
{
	int i;

	i = 0;
	if (str[0] != '1')
		return (0);
	while (str[++i])
		if (str[i] != '0')
			return (0);
	return (((((i - 1) % 3)) == 0));
}

int		count_dict(char **lines)
{
	char	**ptr;
	char	**line;
	char	*number;

	ptr = lines;
	g_length = 0;
	g_power_length = 0;
	while (*lines)
	{
		line = ft_split(*lines, ":");
		number = ft_split(line[0], " ")[0];
		if (ft_strlen(number) < 4)
			g_length++;
		else if (is_power_pattern(number))
			g_power_length++;
		else
			return (0);
		lines++;
	}
	if (!((g_values = malloc(sizeof(int) * (g_length)))
		&& (g_strings = malloc(sizeof(char *) * (g_length)))
		&& (g_powers = malloc(sizeof(char *) * (g_power_length)))))
		return (0);
	return (1);
}

int		parse_dict(char *buffer)
{
	char	**lines;
	char	**line;
	char	*number;
	char	*string;
	int		i;

	if (!buffer || !count_dict((lines = ft_split(buffer, "\n"))))
		return (0);
	i = -1;
	while (*lines)
	{
		line = ft_split(*lines++, ":");
		number = ft_split(line[0], " ")[0];
		free(line);
		line = ft_split(line[1], " ");
		string = ft_strjoin(ft_strstrlen(line), line, " ");
		free(line);
		if (ft_strlen(number) < 4 && (g_strings[++i] = string))
			g_values[i] = ft_natoi(number, 3);
		else if (is_power_pattern(number))
			g_powers[((ft_strlen(number) - 1) / 3) - 1] = string;
		else
			return (0);
	}
	return (1);
}
