/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adda-sil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 02:20:46 by adda-sil          #+#    #+#             */
/*   Updated: 2019/07/24 20:30:49 by mchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	print_grid(t_map *map)
{
	int		i;
	int		j;
	char	c;

	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			c = map->grid[i][j] + '0';
			write(1, &c, 1);
		}
		write(1, "\n", 1);
	}
}

void	print_resolved_grid(t_map *map)
{
	int	i;
	int j;

	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			if (map->grid[i][j] == 0)
				write(1, &map->el.obs, 1);
			else if (map->grid[i][j] == map->max)
				write(1, &map->el.full, 1);
			else
				write(1, &map->el.empty, 1);
		}
		write(1, "\n", 1);
	}
}

int		free_grid_from(t_map *map, int i)
{
	while (i != -1)
		free(map->grid[i--]);
	free(map->grid);
	return (0);
}

int		create_grid(t_map *map)
{
	int		i;
	int		j;
	int		k;

	i = -1;
	k = -1;
	map->grid = malloc(sizeof(unsigned short *) * map->height);
	while (++i < map->height)
	{
		j = -1;
		map->grid[i] = malloc(sizeof(unsigned short) * map->width);
		while (++j < map->width)
		{
			if (map->str[++k] == map->el.empty)
				map->grid[i][j] = 1;
			else if (map->str[k] == map->el.obs)
				map->grid[i][j] = 0;
			else
				return (free_grid_from(map, i));
		}
		if (map->str[k + 1] != '\n')
			return (free_grid_from(map, i));
		k++;
	}
	return (1);
}
