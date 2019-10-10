/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adda-sil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 02:20:38 by adda-sil          #+#    #+#             */
/*   Updated: 2019/07/24 20:33:03 by mchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	free_map_with_grid(t_map *map)
{
	int i;

	i = -1;
	while (++i < map->height)
		free(map->grid[i]);
	free(map);
	return (1);
}

int	exec(t_map *map)
{
	if (map)
	{
		compute(map);
		draw_resolved_square(map);
		print_resolved_grid(map);
		free_map_with_grid(map);
	}
	else
	{
		write(1, "map error\n", 10);
		free(map);
	}
	return (1);
}

int	main(int ac, char **av)
{
	int i;

	i = 0;
	if (ac == 1)
		exec(reader_to_map());
	while (av[++i])
	{
		exec(file_to_map(av[i]));
		if (i != ac - 1)
			write(1, "\n", 1);
	}
	return (0);
}
