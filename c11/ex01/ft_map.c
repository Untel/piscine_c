/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adda-sil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 23:22:31 by adda-sil          #+#    #+#             */
/*   Updated: 2019/07/22 17:10:49 by adda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int i;
	int *res;

	i = -1;
	if (!(res = malloc(sizeof(int) * length)))
		return (0);
	while (++i < length)
		res[i] = f(tab[i]);
	return (res);
}
