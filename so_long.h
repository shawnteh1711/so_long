/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 19:19:29 by steh              #+#    #+#             */
/*   Updated: 2022/04/18 11:57:15 by steh             ###   ########.fr       */
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
#  define RED "\033[0;31m"
#  define GREEN "\033[0;32m"
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
	t_xy	pre_step;
	t_xy	next_step;
}	t_player;

typedef struct	s_enemy
{
	t_xy	actual;
}	t_enemy;

typedef struct	s_image
{
	void	*p;
	void	*p2;
	void	*c;
	void	*c1;
	void	*c2;
	void	*g;
	void	*w;
	void	*exit;
	void	*tmp;
}	t_image;

typedef struct	s_map
{
	int		px;
	int		coin;
	int		exit;
	int		player;
	int		invalid_char;
	int		invalid_file;
	int		empty_file;
	size_t	col_num;
	size_t	row_num;
	char	**maparray;
}	t_map;

typedef struct	s_data 
{
	int			px;
	void		*mlx;
	void		*win;
	int			frame;
	t_map		map;
	t_image		image;
	t_player	player;
	t_enemy		enemy;
}	t_data;

// get next line 
char	*get_next_line(int fd);

// validate map is correct
int		map_validity(char *file, t_map *map, t_data *g);
int		file_is_ber(char *file, t_map *map);
int		map_is_rectangular(char *file, t_map *map);
int		map_surround_wall(char *file, t_map *map);
void	map_contains_cep(char *file, t_map *map);

// validate2
int		check_newline_eof(char *file, t_map *map);

// check utils
char	**create_2d_array(char *file, t_map *map);
int		count_char(char *line, char c);
char	*ft_strdup2(const char *src, size_t col_num);
size_t	ft_strlen2(const char *s);
int		check_invalid_char(char *line, t_map *map);

// setup
void	init_map(t_data *g);
int		put_image(t_data *g);
int		update_player(t_data *g, int i, int j);
int		update_enemy(t_data *g, int i, int j);
void	init_g(t_data *g);

// close
int		close_game(t_data *g);
void	free_memory_invalid_file(t_data *g);
void	free_memory(t_data *g);
int		key_hook(int keycode, t_data *g);

// gameplay
int		move(t_data *g);
int		move_enemy(t_data *g);
void	edit_array(t_data *g);
void	animate_player(t_data *g);
void check_leaks();

// animation
int		animate(t_data *g);
void	render_coin(t_data *g, int i, int j, int type);


#endif