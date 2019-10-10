/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adda-sil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 20:59:14 by adda-sil          #+#    #+#             */
/*   Updated: 2019/07/25 19:26:01 by adda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int c;

	c = *a;
	*a = *b;
	*b = c;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int i;
	int ordered;

	ordered = 0;
	while (!ordered)
	{
		i = 0;
		ordered = 1;
		while (++i < size)
		{
			if (tab[i - 1] > tab[i])
			{
				ft_swap(&tab[i - 1], &tab[i]);
				ordered = 0;
			}
		}
	}
}
