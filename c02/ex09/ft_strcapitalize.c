/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adda-sil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 01:35:14 by adda-sil          #+#    #+#             */
/*   Updated: 2019/07/09 00:12:37 by adda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_lowercase(char c)
{
	return (c >= 'a' && c <= 'z');
}

int		is_uppercase(char c)
{
	return (c >= 'A' && c <= 'Z');
}

int		is_alphanumeric(char c)
{
	return (is_lowercase(c)
			|| is_uppercase(c)
			|| (c >= '0' && c <= '9'));
}

char	*ft_strcapitalize(char *str)
{
	int i;

	i = -1;
	if (is_lowercase(str[0]))
		str[0] = str[0] - 32;
	while (str[++i] != '\0')
		if (!is_alphanumeric(str[i]) && is_lowercase(str[i + 1]))
			str[i + 1] = str[i + 1] - 32;
		else if (is_alphanumeric(str[i]) && is_uppercase(str[i + 1]))
			str[i + 1] = str[i + 1] + 32;
	return (str);
}
