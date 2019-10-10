/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adda-sil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 02:26:14 by adda-sil          #+#    #+#             */
/*   Updated: 2019/07/24 20:38:04 by mchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

int		ft_natoi(char *str, int n);
int		ft_strlen(char *str);
int		is_num(char c);
char	*ft_strcat(char *dest, char *src);
char	*ft_strdup(char *str);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strncat(char *dest, char *src, unsigned int nb);
#endif
