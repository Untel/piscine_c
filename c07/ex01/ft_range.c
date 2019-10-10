/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adda-sil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 19:02:44 by adda-sil          #+#    #+#             */
/*   Updated: 2019/07/15 19:19:15 by adda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int *tab;
	int *ref;

	if (min >= max)
		return (0);
	tab = malloc(sizeof(int) * (max - min));
	ref = tab;
	while (max > min)
		*tab++ = min++;
	return (ref);
}
