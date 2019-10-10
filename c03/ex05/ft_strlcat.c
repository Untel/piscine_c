/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adda-sil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 17:14:11 by adda-sil          #+#    #+#             */
/*   Updated: 2019/07/09 15:59:57 by adda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	unsigned int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int nb)
{
	char			*dest_ptr;
	char			*src_ptr;
	unsigned int	i;
	unsigned int	dest_len;

	dest_ptr = dest;
	src_ptr = src;
	i = nb;
	while (i-- != 0 && *dest_ptr != '\0')
		dest_ptr++;
	dest_len = dest_ptr - dest;
	i = nb - dest_len;
	if (i == 0)
		return (dest_len + ft_strlen(src_ptr));
	while (*src_ptr != '\0')
	{
		if (i != 1)
		{
			*dest_ptr++ = *src_ptr;
			i--;
		}
		src_ptr++;
	}
	*dest_ptr = '\0';
	return (dest_len + (src_ptr - src));
}
