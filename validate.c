/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 14:52:47 by steh              #+#    #+#             */
/*   Updated: 2022/04/12 17:10:59 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// check the extension is .ber -done
// must have 1 e, 1 c, 1 p 
// must be rectangular
// must surround with walls(1)
int	file_is_ber(char *file)
{
	char	*ext;
	int		len;

	len = ft_strlen(file);
	ext = (char *)ft_memchr(file, '.', len);
	if (!ft_strncmp(ext, ".ber", len))
		return (TRUE);
	return (FALSE);
}

// check map is rectangular by using get_next_line to read
// length of first line and compare length with subsequent
// line. If same length then it is same.
// last line dont have newline which may cause problem
int	map_is_rectangular(char *file, t_map *map)
{
	int		fd;
	int		is_rect;
	char	*line;
	size_t	i;

	i = 0;
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	if (line == NULL)
		return (FALSE);
	map->col_num = ft_strlen2(line);
	map->row_num = 0;
	while (line)
	{
		if (ft_strlen2(line) != map->col_num)
			is_rect = FALSE;
		free(line);
		line = get_next_line(fd);
		map->row_num++;
	}
	free(line);
	close(fd);
	if (is_rect == FALSE)
		return (FALSE);
	return (TRUE);
}

int	map_surround_wall(char *file, t_map *map)
{
	size_t	i;
	size_t	j;

	i = 1;
	j = 0;
	map->maparray = create_2d_array(file, map);
	while (j < map->col_num)
	{
		if (map->maparray[0][j] != '1')
			return (FALSE);
		if (map->maparray[map->row_num - 1][j] != '1')
			return (FALSE);
		j++;
	}
	while (i < map->row_num - 1)
	{
		if (map->maparray[i][map->col_num] != '1'
		&& map->maparray[i][0] != '1')
			return (FALSE);
		i++;
	}
	// while (i < map->row_num)
	// 	free(map->maparray[i++]);
	return (TRUE);
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
	close(fd);
	if (!map->coin || !map->exit || map->player != 1)
		return (FALSE);
	return (TRUE);
}
