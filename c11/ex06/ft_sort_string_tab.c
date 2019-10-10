/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adda-sil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 16:52:18 by adda-sil          #+#    #+#             */
/*   Updated: 2019/07/22 17:03:47 by adda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = -1;
	while (s1[++i] != '\0')
		if (s1[i] != s2[i])
			break ;
	return (s1[i] - s2[i]);
}

void	ft_sort_string_tab(char **tab)
{
	int		i;
	char	*tmp;
	int		ordered;

	ordered = 0;
	while (!ordered)
	{
		i = 0;
		ordered = 1;
		while (tab[++i])
			if (ft_strcmp(tab[i - 1], tab[i]) > 0)
			{
				tmp = tab[i - 1];
				tab[i - 1] = tab[i];
				tab[i] = tmp;
				ordered = 0;
			}
	}
}
