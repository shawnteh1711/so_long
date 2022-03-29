/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 14:52:47 by steh              #+#    #+#             */
/*   Updated: 2022/03/29 20:31:48 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "so_long.h"

// check the extension is .ber -done
// must have 1 e, 1 c, 1 p 
// must be rectangular
// must surround with walls(1)

int	count_char(char *line, char c)
{
	int		count;

	count = 0;
	while(*line)
	{
		if (*line++ == c)
			count++;
	}
	return (count);
}

int	is_ber(char *file)
{
	char	*ext;
	int		len;

	len = ft_strlen(file);
	ext = (char *)ft_memchr(file, '.', len);
	if (!ft_strncmp(ext, ".ber", len))
		return (1);
	return (0);
}


// check map is rectangular by using get_next_line to read
// length of first line and compare length with subsequent
// line. If same length then it is same.
int	is_rectangular(char *file)
{
	int		fd;
	int		is_rect;
	size_t	col_len;
	char	*line;

	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	col_len = ft_strlen(line);
	while (line)
	{
		if (ft_strlen(line) != col_len)
			is_rect = FALSE;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	if (!is_rect)
		return (1);
	return (0);
}

int	map_contains_cep(char *file, t_map *map)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		map->coin += count_char(line, 'C');
		map->exit += count_char(line, 'E');
		map->player += count_char(line, 'P');
		free(line);
		line = get_next_line(fd);
	}
	if (!map->coin || !map->exit || map->player != 1)
		return (1);
	return (0);
}

// check first row and last row all surround with 1
// check between roll, first col and last col is 1
int	map_surround_wall(char *file, t_map *map)
{
	return (0);
}

int	map_validity(char *file, t_map *map)
{
	if (!is_ber(file) || !is_rectangular(file) 
		|| !map_contains_cep(file, map) || map_surround_wall(file, map))
		return (1);
	return (0);
}