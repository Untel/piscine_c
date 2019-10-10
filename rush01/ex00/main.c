/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adda-sil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 17:14:13 by adda-sil          #+#    #+#             */
/*   Updated: 2019/07/14 22:24:17 by tvanhers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_grid(char grid[4][4]);
void	print_view(char view[4][5]);
int		back_track(int i, int j, char grid[4][4], char view[4][5]);
int		parse_views(int argc, char **argv, char view[4][5]);
int		valid_arg(char *str);
int		valid_arg2(char *str);

int		main(int argc, char **argv)
{
	char view[4][5];
	char grid[4][4];

	if (argc != 2 || !valid_arg(argv[1]))
	{
		write(1, "ERROR\n", 6);
		return (0);
	}
	if (!valid_arg2(argv[1]))
	{
		write(1, "PAS DE SOLUTION\n", 15);
		return (0);
	}
	parse_views(argc, argv, view);
	back_track(0, 0, grid, view);
	print_grid(grid);
}
