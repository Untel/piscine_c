/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adda-sil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 15:51:51 by adda-sil          #+#    #+#             */
/*   Updated: 2019/07/08 21:13:47 by adda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char			*dest_ptr;
	unsigned int	i;

	dest_ptr = dest;
	i = 0;
	while (*dest)
		dest++;
	while (i < nb && (*dest++ = *src++))
		i++;
	if (src[-1])
		*dest++ = '\0';
	return (dest_ptr);
}
