/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adda-sil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 15:43:51 by adda-sil          #+#    #+#             */
/*   Updated: 2019/07/04 16:50:12 by adda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_res(int i, int j)
{
	char ai;
	char bi;
	char aj;
	char bj;

	ai = (i / 10) + '0';
	bi = (i % 10) + '0';
	aj = (j / 10) + '0';
	bj = (j % 10) + '0';
	write(1, &ai, 1);
	write(1, &bi, 1);
	write(1, " ", 1);
	write(1, &aj, 1);
	write(1, &bj, 1);
}

void	ft_print_comb2(void)
{
	int	i;
	int	j;

	i = 0;
	while (i <= 98)
	{
		j = i + 1;
		while (j <= 99)
		{
			ft_print_res(i, j);
			if (i == 98 && j == 99)
				return ;
			write(1, ", ", 2);
			j++;
		}
		i++;
	}
}
