/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adda-sil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 02:25:52 by adda-sil          #+#    #+#             */
/*   Updated: 2019/07/24 20:34:18 by mchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_H
# define FILE_H
# include "types.h"
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# define BUF_SIZE 4096

t_map	*read_to_buffer();
t_map	*file_to_map(char *filename);
t_map	*reader_to_map();
int		create_grid(t_map *map);
#endif
