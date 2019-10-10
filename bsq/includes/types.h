/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adda-sil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 02:26:08 by adda-sil          #+#    #+#             */
/*   Updated: 2019/07/24 21:12:02 by mchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

typedef struct				s_el {
	char empty;
	char full;
	char obs;
}							t_el;
typedef struct				s_map {
	t_el					el;
	char					*str;
	unsigned short			**grid;
	int						width;
	int						height;
	int						max;
	int						max_x;
	int						max_y;
}							t_map;
#endif
