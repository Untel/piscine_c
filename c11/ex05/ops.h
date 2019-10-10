/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adda-sil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 01:02:23 by adda-sil          #+#    #+#             */
/*   Updated: 2019/07/22 16:51:42 by adda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPS_H
# define OPS_H
# include <unistd.h>

int					add(int a, int b);
int					substract(int a, int b);
int					divide(int a, int b);
int					modulo(int a, int b);
int					multiply(int a, int b);
int					ft_atoi(char *str);
void				ft_putnbr(int nb);
#endif
