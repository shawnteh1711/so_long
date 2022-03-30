/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 19:19:29 by steh              #+#    #+#             */
/*   Updated: 2022/03/30 14:42:36 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
#  define TRUE 1
#  define FALSE 0
# endif

# include <stdio.h>

// RDONLY
# include <fcntl.h>

// for free() and malloc()
# include <stdlib.h>

// for read() and close()
# include <unistd.h>

# include "libft/libft.h"
# include "ft_printf/includes/ft_printf.h"
# include "minilibx_opengl_20191021/mlx.h"

typedef struct	s_map
{
	int		px;
	int		coin;
	int		exit;
	int		player;
	size_t	col_num;
	size_t	row_num;
	char	**maparray;
}	t_map;

typedef struct	s_data 
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		px;
	t_map	map;
}	t_data;


// get next line 
char	*get_next_line(int fd);

// validate map is correct
int		map_validity(char *file, t_map *map);
int		is_ber(char *file);
int		is_rectangular(char *file, t_map *map);
int		map_surround_wall(char *file, t_map *map);
int		map_contains_cep(char *file, t_map *map);
char	*ft_strdup2(const char *src, size_t col_num);

#endif