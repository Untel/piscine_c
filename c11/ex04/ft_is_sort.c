/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adda-sil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 00:31:22 by adda-sil          #+#    #+#             */
/*   Updated: 2019/07/22 21:20:56 by adda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_croissant(int *tab, int length, int (*f)(int, int))
{
	int i;

	i = 0;
	while (++i < length)
		if (f(tab[i - 1], tab[i]) > 0)
			return (0);
	return (1);
}

int	is_decroissant(int *tab, int length, int (*f)(int, int))
{
	int i;

	i = 0;
	while (++i < length)
		if (f(tab[i - 1], tab[i]) < 0)
			return (0);
	return (1);
}

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	if (is_croissant(tab, length, f) || is_decroissant(tab, length, f))
		return (1);
	return (0);
}
