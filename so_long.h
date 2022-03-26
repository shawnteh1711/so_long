/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 19:19:29 by steh              #+#    #+#             */
/*   Updated: 2022/03/26 18:43:06 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
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
	int	px;
}	t_map;

typedef struct	s_data 
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		px;
	t_map		map;
}	t_data;


// get next line 
char	*get_next_line(int fd);
char	*ft_read_and_save(int fd, char *save_line);
char	*ft_get_line(char *save_line);
char	*ft_save_next_line(char *save_line);

// validate map is correct
int		map_validity(char *file);


#endif