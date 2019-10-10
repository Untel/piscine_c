/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adda-sil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 00:54:28 by adda-sil          #+#    #+#             */
/*   Updated: 2019/07/22 21:14:21 by adda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ops.h"

int		is_op(char c)
{
	return (c == '+'
			|| c == '-'
			|| c == '/'
			|| c == '%'
			|| c == '*');
}

int		get_op_idx(char op)
{
	if (op == '+')
		return (0);
	if (op == '-')
		return (1);
	if (op == '/')
		return (2);
	if (op == '%')
		return (3);
	return (4);
}

void	init_fn_table(int (*fn[5])(int, int))
{
	fn[0] = add;
	fn[1] = substract;
	fn[2] = divide;
	fn[3] = modulo;
	fn[4] = multiply;
}

int		main(int ac, char **argv)
{
	int					b;
	char				op;
	int					(*fn[5])(int, int);

	if (ac != 4)
		return (0);
	if (!argv[2] || argv[2][1] || !is_op((op = argv[2][0])))
	{
		write(1, "0\n", 2);
		return (0);
	}
	init_fn_table(fn);
	b = ft_atoi(argv[3]);
	if (b == 0 && (op == '/' || op == '%'))
	{
		if (op == '/')
			write(1, "Stop : division by zero\n", 24);
		if (op == '%')
			write(1, "Stop : modulo by zero\n", 22);
		return (0);
	}
	ft_putnbr(fn[get_op_idx(op)](ft_atoi(argv[1]), b));
	write(1, "\n", 1);
	return (0);
}
