/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digits.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adda-sil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 14:03:45 by adda-sil          #+#    #+#             */
/*   Updated: 2019/07/21 22:56:11 by adda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIGITS_H
# define DIGITS_H
# include <stdlib.h>
# include <stdio.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>

char	**g_strings;
char	**g_powers;
int		*g_values;
int		g_length;
int		g_power_length;
char	*g_arg_nbr;
char	*read_dict(char *filename);
int		*char_to_3digits_tabs(char *str, int len, int tab_len);
int		number_length(int nbr);
int		ft_natoi(char *str, int nb);
int		ft_strlen(char *str);
int		ft_strstrlen(char **str);
int		ft_power(int nb, int power);
int		parse_dict(char *buffer);
char	*digits_to_litteral(int number);
char	*ft_strjoin(int size, char **strs, char *sep);
char	*get_litteral(int number);
char	*print_powered_digits(int *tab, int tab_len);
char	**ft_split(char *str, char *charset);
int		ft_putstr(char *str);
int		check_args(int ac, char **av);
#endif
