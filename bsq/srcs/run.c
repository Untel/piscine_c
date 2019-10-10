/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adda-sil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 02:21:01 by adda-sil          #+#    #+#             */
/*   Updated: 2019/07/24 20:32:25 by mchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	cpt_max(t_map *map, int i, int j)
{
	int max;

	if (map->grid[i - 1][j - 1] <= map->grid[i][j - 1])
	{
		if (map->grid[i - 1][j - 1] <= map->grid[i - 1][j])
			max = map->grid[i - 1][j - 1];
		else
			max = map->grid[i - 1][j];
	}
	else
	{
		if (map->grid[i][j - 1] <= map->grid[i - 1][j])
			max = map->grid[i][j - 1];
		else
			max = map->grid[i - 1][j];
	}
	map->grid[i][j] = max + 1;
}

void	compute(t_map *map)
{
	int i;
	int j;

	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			if (!(i == 0 || j == 0 || map->grid[i][j] == 0))
				cpt_max(map, i, j);
			if (map->max < map->grid[i][j])
			{
				map->max = map->grid[i][j];
				map->max_x = i;
				map->max_y = j;
			}
		}
	}
}

void	draw_resolved_square(t_map *map)
{
	int len_x;
	int len_y;

	len_x = map->max;
	while (--len_x > -1)
	{
		len_y = map->max;
		while (--len_y > -1)
			map->grid[map->max_x - len_x][map->max_y - len_y] = map->max + 1;
	}
	map->max += 1;
}
