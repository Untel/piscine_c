/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adda-sil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 00:38:04 by adda-sil          #+#    #+#             */
/*   Updated: 2019/07/15 21:57:28 by adda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		is_valid_char(char c);
int		check_base(char *base);
int		ft_atoi_base(char *str, char *base, unsigned int base_size);

int		ft_nb_char_base(long int nbr, int base_size)
{
	if (nbr > 0)
		return (1 + (ft_nb_char_base(nbr / base_size, base_size)));
	else
		return (0);
}

char	*alloc_str(unsigned int nb, int base_size, char *base, int is_neg)
{
	char	*ptr;
	char	*save;
	int		len;

	len = nb > 0 ? (ft_nb_char_base(nb, base_size) + is_neg) : 1;
	ptr = malloc(sizeof(char) * len + 1);
	if (!ptr || ptr == NULL)
		return (0);
	save = ptr + len;
	*save-- = '\0';
	if (nb == 0)
		*save-- = base[nb % base_size];
	while (nb > 0)
	{
		*save-- = base[nb % base_size];
		nb = nb / base_size;
	}
	if (is_neg)
		*save-- = '-';
	return (ptr);
}

char	*ft_putnbr_base(int nbr, char *base, unsigned int base_size)
{
	unsigned int	nb;
	int				is_neg;

	is_neg = 0;
	if (nbr < 0)
	{
		nb = (unsigned int)(nbr * -1);
		is_neg = 1;
	}
	else
		nb = (unsigned int)nbr;
	return (alloc_str(nb, base_size, base, is_neg));
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int					nb;
	char				*str;
	unsigned int		from_base_size;
	unsigned int		to_base_size;

	if (!((from_base_size = check_base(base_from))
		&& (to_base_size = check_base(base_to))))
		return (0);
	nb = ft_atoi_base(nbr, base_from, from_base_size);
	str = ft_putnbr_base(nb, base_to, to_base_size);
	return (str);
}
