/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   views_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adda-sil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 05:37:42 by adda-sil          #+#    #+#             */
/*   Updated: 2019/07/14 22:35:21 by tvanhers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	print_grid(char grid[4][4]);

int		check_row_left(int x, char grid[4][4], char view)
{
	int		i;
	char	max;
	char	v;

	i = -1;
	max = 0;
	v = '0';
	while (++i < 4)
	{
		if (grid[x][i] && grid[x][i] > max)
		{
			max = grid[x][i];
			v++;
		}
	}
	return (max == '4' ? v == view : 1);
}

int		check_row_right(int x, char grid[4][4], char view)
{
	int		i;
	char	max;
	char	v;

	i = 4;
	max = 0;
	v = '0';
	while (--i >= 0)
	{
		if (grid[x][i] && grid[x][i] > max)
		{
			max = grid[x][i];
			v++;
		}
	}
	return (max == '4' ? v == view : 1);
}

int		check_col_up(int y, char grid[4][4], char view)
{
	int		i;
	char	max;
	char	v;

	i = -1;
	max = 0;
	v = '0';
	while (++i < 4)
	{
		if (grid[i][y] && grid[i][y] > max)
		{
			max = grid[i][y];
			v++;
		}
	}
	return (max == '4' ? v == view : 1);
}

int		check_col_down(int y, char grid[4][4], char view)
{
	int		i;
	char	max;
	char	v;

	i = 4;
	max = 0;
	v = '0';
	while (--i >= 0)
	{
		if (grid[i][y] && grid[i][y] > max)
		{
			max = grid[i][y];
			v++;
		}
	}
	return (max == '4' ? v == view : 1);
}

int		views_check(int i, int j, char grid[4][4], char view[4][5])
{
	int is_valid;

	is_valid = 1;
	is_valid = is_valid && check_row_left(j, grid, view[2][j]);
	is_valid = is_valid && check_col_up(i, grid, view[0][i]);
	if (j == 3)
		is_valid = is_valid && check_row_right(j, grid, view[3][j]);
	if (i == 3)
		is_valid = is_valid && check_col_down(i, grid, view[1][i]);
	return (is_valid);
}
