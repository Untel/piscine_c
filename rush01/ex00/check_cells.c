/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cells.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adda-sil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 16:27:27 by adda-sil          #+#    #+#             */
/*   Updated: 2019/07/14 22:22:20 by tvanhers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		views_check(int x, int y, char grid[4][4], char view[4][5]);

int		still_on_row(char box, int row, char grid[4][4])
{
	int i;

	i = -1;
	while (++i < 4)
		if (grid[row][i] == box)
			return (1);
	return (0);
}

int		still_on_col(char box, int col, char grid[4][4])
{
	int i;

	i = -1;
	while (++i < 4)
		if (grid[i][col] == box)
			return (1);
	return (0);
}

void	print_grid(char grid[4][4])
{
	int i;
	int j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (!grid[i][j])
				write(1, "X", 1);
			else
				write(1, &grid[i][j], 1);
			write(1, " ", 1);
		}
		write(1, "\n", 1);
	}
	write(1, "-------\n", 8);
}

int		back_track(int i, int j, char grid[4][4], char draft[4][4],
		char view[4][5])
{
	int box;
	int check;
	int x;
	int y;

	box = '0';
	if (i == 4)
		return (1);
	while (++box <= '4')
	{
		if (!still_on_col(box, j, draft)
			&& !still_on_row(box, i, draft)
			&& views_check(i, j, draft, view))
		{
			draft[i][j] = box;
			y = j + 1;
			x = i;
			if (y == 4)
			{
				y = 0;
				x++;
			}
			if (back_track(x, y, grid, draft, view))
			{
				grid[i][j] = box;
				return (1);
			}
			draft[i][j] = '\0';
		}
	}
	return (0);
}
