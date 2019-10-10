/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proto.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adda-sil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 02:25:59 by adda-sil          #+#    #+#             */
/*   Updated: 2019/07/24 02:26:01 by adda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTO_H
# define PROTO_H
# include "types.h"

void	print_map(t_map *map);
void	print_grid(t_map *map);
void	print_resolved_grid(t_map *map);
void	print_bigger(t_map *map);
void	compute(t_map *map);
void	draw_resolved_square(t_map *map);
#endif
