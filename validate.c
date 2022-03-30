/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 14:52:47 by steh              #+#    #+#             */
/*   Updated: 2022/03/30 20:58:14 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// check the extension is .ber -done
// must have 1 e, 1 c, 1 p 
// must be rectangular
// must surround with walls(1)

int	count_char(char *line, char c)
{
	int		count;

	count = 0;
	while (*line)
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
		return (0);
	return (1);
}

// check map is rectangular by using get_next_line to read
// length of first line and compare length with subsequent
// line. If same length then it is same.
int	is_rectangular(char *file, t_map *map)
{
	int		fd;
	int		is_rect;
	char	*line;

	// rectangular last row dont have newline so cause issue
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	map->col_num = ft_strlen(line);
	map->row_num = 0;
	while (line)
	{
		if (ft_strlen(line) != map->col_num)
			is_rect = FALSE;
		free(line);
		line = get_next_line(fd);
		map->row_num++;
	}
	close(fd);
	if (!is_rect)
		return (0);
	return (1);
}

int	map_surround_wall(char *file, t_map *map)
{
	int fd;
	char *line;
	size_t i;
	size_t j;
	
	if (!is_rectangular(file, map))
		return (0);
	map->maparray = (char **)malloc(sizeof(char *) * map->row_num);
	fd = open(file, O_RDONLY);
	i = 0;
	while (i < map->row_num)
	{
		line = get_next_line(fd);
		map->maparray[i++] = ft_strdup2(line, map->col_num);
		free(line);
	}
	close(fd);
	i = 1;
	j = 0;
	// first row
	// last row
	while (j < map->col_num)
	{
		if (map->maparray[0][j] != '1')
			return (0);
		if (map->maparray[map->row_num - 1][j] != '1')
			return (0);
		j++;
	}

	// between row and first and last column
	while (i < map->row_num - 2)
	{
		if (map->maparray[i][map->col_num - 1] != '1'
		&& map->maparray[i][0] != '1')
			return (0);
		i++;
	}
	free(map->maparray);
	return (1);
}

char	*ft_strdup2(const char *src, size_t col_num)
{
	char	*dest;
	size_t	i;

	i = 0;
	dest = (char *)malloc(sizeof(char) * (col_num));
	if (dest == NULL)
		return (NULL);
	while (i < col_num - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

// check first row and last row all surround with 1
// check between roll, first col and last col is 1
// int	map_surround_wall(char *file, t_map *map)
// {
// 	int		fd;
// 	char	*line;
// 	char	**linearray;

// 	fd = open(file, O_RDONLY);
// 	line = get_next_line(fd);
// 	linearray = (char **)malloc(map->col_num * sizeof(char *));
// 	while (line)
// 	{
	
// 		ft_printf("line: %s\n", line);
// 		free(line);
// 		line = get_next_line(fd);
// 	}
// 	ft_printf("row: %d", map->row_num);
// 	ft_printf("last row1: %s", line[4]);
// 	close(fd);
// 	return (0);
// }



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
		return (0);
	// if (!map_surround_wall(file, map))
	// 	return (0);
	return (1);
}
