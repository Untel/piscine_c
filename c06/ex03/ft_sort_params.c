/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adda-sil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 00:26:05 by adda-sil          #+#    #+#             */
/*   Updated: 2019/07/11 02:33:33 by adda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_params(int argc, char **argv)
{
	int i;
	int j;

	i = 0;
	while (++i < argc)
	{
		j = -1;
		while (argv[i][++j])
			write(1, &argv[i][j], 1);
		write(1, "\n", 1);
	}
}

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = -1;
	while (s1[++i] != '\0')
		if (s1[i] != s2[i])
			break ;
	return (s1[i] - s2[i]);
}

int		main(int argc, char **argv)
{
	int		i;
	char	*tmp;
	int		ordered;

	ordered = 0;
	while (!ordered)
	{
		i = 1;
		ordered = 1;
		while (++i < argc)
			if (ft_strcmp(argv[i - 1], argv[i]) > 0)
			{
				tmp = argv[i - 1];
				argv[i - 1] = argv[i];
				argv[i] = tmp;
				ordered = 0;
			}
	}
	print_params(argc, argv);
}
