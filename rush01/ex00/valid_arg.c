/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanhers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 12:14:13 by tvanhers          #+#    #+#             */
/*   Updated: 2019/07/14 22:34:36 by tvanhers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		valid_arg(char *str)
{
	int i;

	i = 0;
	if (!(str[i]))
		return (0);
	if (ft_strlen(str) > 31)
		return (0);
	while (str[i])
	{
		if ((str[i] >= '1' && str[i] <= '4') || str[i] == ' ')
			i++;
		else
			return (0);
	}
	i = 0;
	while (str[i])
	{
		if (i % 2 == 1 && str[i] == ' ')
			i++;
		else if (i % 2 == 0 && str[i] >= '1' && str[i] <= '4')
			i++;
		else
			return (0);
	}
	return (1);
}

int		valid_arg2(char *str)
{
	int i;

	i = 0;
	while (i <= 6)
	{
		if (str[i] + str[i + 8] >= 99 && str[i] + str[i + 8] <= 101)
		{
			i += 2;
		}
		else
			return (0);
	}
	i = 16;
	while (i <= 22)
	{
		if (str[i] + str[i + 8] >= 99 && str[i] + str[i + 8] <= 101)
			i += 2;
		else
			return (0);
	}
	return (1);
}
