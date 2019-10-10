/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adda-sil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 02:20:30 by adda-sil          #+#    #+#             */
/*   Updated: 2019/07/24 02:20:32 by adda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	*free_map(t_map *map)
{
	free(map);
	return (0);
}

t_map	*assign_attrs(char *buffer, int len)
{
	int		i;
	t_map	*map;

	map = malloc(sizeof(t_map));
	i = -1;
	while (buffer[++i] != '\n')
		if (buffer[i] == '\0')
			return (free_map(map));
	if (!(map->height = ft_natoi(buffer, i - 3)))
		return (free_map(map));
	map->width = (len - i - 2) / (map->height);
	map->el.empty = buffer[i - 3];
	map->el.obs = buffer[i - 2];
	map->el.full = buffer[i - 1];
	map->max = 0;
	map->max_y = 0;
	map->max_x = 0;
	map->str = &buffer[i + 1];
	if (!(create_grid(map)))
		return (free_map(map));
	free(buffer);
	return (map);
}

char	*file_to_buffer(int fd)
{
	char	*final_buffer;
	char	*old;
	int		len;
	char	buffer[BUF_SIZE];
	int		ret;

	len = 1;
	final_buffer = malloc(sizeof(char) * 1);
	while ((ret = read(fd, buffer, BUF_SIZE - 1)) > 0)
	{
		len += ret;
		old = final_buffer;
		final_buffer = malloc(sizeof(char) * (len));
		final_buffer = ft_strncat(final_buffer, old, len);
		final_buffer = ft_strncat(final_buffer, buffer, len);
	}
	final_buffer[len - 1] = 0;
	return (final_buffer);
}

t_map	*reader_to_map(void)
{
	char	*buffer;

	if (!(buffer = file_to_buffer(0)))
	{
		free(buffer);
		return (0);
	}
	return (assign_attrs(buffer, ft_strlen(buffer + 1)));
}

t_map	*file_to_map(char *filename)
{
	char	*buffer;
	int		fd;

	if ((fd = open(filename, O_RDONLY)) == -1)
		return (0);
	if (!(buffer = file_to_buffer(fd)))
	{
		free(buffer);
		return (0);
	}
	return (assign_attrs(buffer, ft_strlen(buffer + 1)));
}
