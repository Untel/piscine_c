/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adda-sil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 19:50:59 by adda-sil          #+#    #+#             */
/*   Updated: 2019/07/16 16:02:20 by adda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int i;
	int res;

	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	i = 0;
	res = 1;
	while (++i <= nb)
		res *= i;
	return (res);
}
