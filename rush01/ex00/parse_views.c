/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adda-sil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 05:52:51 by adda-sil          #+#    #+#             */
/*   Updated: 2019/07/14 22:27:48 by tvanhers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		parse_views(int argc, char **argv, char view[4][5])
{
	int i;
	int j;
	int k;

	if (argc > 2)
		return (0);
	i = -1;
	j = 0;
	k = 0;
	while (argv[1][++i])
	{
		if (argv[1][i] == ' ')
			continue ;
		view[k][j] = argv[1][i];
		j++;
		if (j == 4)
		{
			view[k][j] = '\0';
			j = 0;
			k++;
		}
	}
	return (1);
}

void	print_view(char view[4][5])
{
	int		i;
	int		j;
	char	*dir[4];

	dir[0] = "up";
	dir[1] = "down";
	dir[2] = "left";
	dir[3] = "right";
}
