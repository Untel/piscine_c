/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adda-sil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 09:29:46 by adda-sil          #+#    #+#             */
/*   Updated: 2019/07/08 20:29:33 by adda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int i;

	i = -1;
	while (s1[++i] != '\0')
		if (s1[i] != s2[i])
			break ;
	return (s1[i] - s2[i]);
}