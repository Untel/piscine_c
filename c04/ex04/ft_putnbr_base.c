/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adda-sil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 13:28:41 by adda-sil          #+#    #+#             */
/*   Updated: 2019/07/10 18:19:37 by adda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		is_space(char c)
{
	return (c == '\t'
			|| c == '\n'
			|| c == '\v'
			|| c == '\f'
			|| c == '\r'
			|| c == ' ');
}

int		is_valid_char(char c)
{
	return (!(c == '-' || c == '+' || is_space(c)));
}

int		check_base(char *base)
{
	int				i;
	unsigned int	j;

	i = -1;
	while (base[++i])
	{
		if (!is_valid_char(base[i]))
			return (0);
		j = i;
		while (base[++j])
			if (base[j] == base[i])
				return (0);
	}
	return (i <= 1 ? 0 : i);
}

void	recursive_print(long int nbr, char *base, unsigned int base_size)
{
	char l;

	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = nbr * -1;
	}
	l = base[nbr % base_size];
	nbr = nbr / base_size;
	if (nbr > 0)
		recursive_print(nbr, base, base_size);
	write(1, &l, 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long int		nb;
	unsigned int	base_size;

	nb = (long int)nbr;
	base_size = check_base(base);
	if (base_size)
		recursive_print(nbr, base, base_size);
}
