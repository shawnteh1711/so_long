/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 19:19:29 by steh              #+#    #+#             */
/*   Updated: 2022/04/12 20:31:18 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
#  define ESC 53
#  define LEFT 0
#  define RIGHT 2
#  define UP 13
#  define DOWN 1
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
typedef struct	s_xy
{
	int	x;
	int	y;
}	t_xy;

typedef struct	s_player
{
	int		moves;
	t_xy	actual;
	t_xy	attempt;
}	t_player;

typedef struct	s_enemy
{
	t_xy	actual;
}	t_enemy;

typedef struct	s_image
{
	void	*p;
	void	*c;
	void	*e;
	void	*w;
	void	*exit;
}	t_image;

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
	int			px;
	void		*mlx;
	void		*win;
	t_map		map;
	t_image		image;
	t_player	player;
	t_enemy		enemy;
}	t_data;


// get next line 
char	*get_next_line(int fd);

// validate map is correct
int		map_validity(char *file, t_map *map);
int		file_is_ber(char *file);
int		map_is_rectangular(char *file, t_map *map);
int		map_surround_wall(char *file, t_map *map);
int		map_contains_cep(char *file, t_map *map);

// check utils
char	**create_2d_array(char *file, t_map *map);
int		count_char(char *line, char c);
char	*ft_strdup2(const char *src, size_t col_num);
size_t	ft_strlen2(const char *s);

// setup
void	init_map(t_data *g);
void	put_image(t_data *g);
int		update_p(t_data *g, int i, int j);

// close
int		close_game(t_data *g);
void	free_array(t_data *g);
int		key_hook(int keycode, t_data *g);

#endif