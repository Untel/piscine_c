/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adda-sil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 19:16:43 by adda-sil          #+#    #+#             */
/*   Updated: 2019/07/15 22:04:04 by adda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int *ref;
	int i;

	i = 0;
	if (min >= max)
		return (0);
	ref = malloc(sizeof(int) * (max - min));
	if (!ref)
	{
		*range = 0;
		return (0);
	}
	*range = ref;
	while (max > min + i)
	{
		ref[i] = min + i;
		i++;
	}
	return (i);
}
