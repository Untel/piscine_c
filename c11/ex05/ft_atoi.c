/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adda-sil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 17:37:30 by adda-sil          #+#    #+#             */
/*   Updated: 2019/07/10 18:12:16 by adda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_space(char c)
{
	return (c == '\t'
			|| c == '\n'
			|| c == '\v'
			|| c == '\f'
			|| c == '\r'
			|| c == ' ');
}

int	is_num(char c)
{
	return (c >= '0' && c <= '9');
}

int	is_sign(char c)
{
	return (c == '-' || c == '+');
}

int	ft_atoi(char *str)
{
	unsigned int	i;
	unsigned int	sign;
	unsigned int	count;

	i = 0;
	count = 0;
	sign = 0;
	while (is_space(str[i]))
		i++;
	while (is_sign(str[i]))
	{
		if (str[i] == '-')
			sign++;
		i++;
	}
	while (str[i])
	{
		if (!is_num(str[i]) && count > 0)
			break ;
		if (!is_num(str[i]) && count == 0)
			return (0);
		count = count * 10 + (str[i] - '0');
		i++;
	}
	return (sign % 2 ? -count : count);
}
