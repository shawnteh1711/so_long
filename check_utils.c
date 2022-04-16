/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 11:53:43 by steh              #+#    #+#             */
/*   Updated: 2022/04/16 16:46:46 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

char	**create_2d_array(char *file, t_map *map)
{
	int		fd;
	char	*line;
	size_t	i;

	fd = open(file, O_RDONLY);
	i = 0;
	map->maparray = (char **)malloc(sizeof(char *) * map->row_num);
	if (map->maparray == NULL)
		return (FALSE);
	while (i < map->row_num)
	{
		line = get_next_line(fd);
		map->maparray[i++] = ft_strdup2(line, map->col_num);
		free(line);
	}
	close(fd);
	return (map->maparray);
}

char	*ft_strdup2(const char *src, size_t col_num)
{
	char	*dest;
	size_t	i;

	i = 0;
	dest = (char *)malloc(sizeof(char) * (col_num + 1));
	if (dest == NULL)
		return (NULL);
	if (col_num == 0)
		return (NULL);
	while (i < col_num)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

size_t	ft_strlen2(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	return (i);
}

int	check_invalid_char(char *line, t_map *map)
{
	size_t	i;
	char	*elements;

	i = 0;
	elements = "10ECGP";
	while (i < map->col_num)
	{
		if (!ft_strchr(elements, line[i]))
			return (1);
		i++;
	}
	return (0);
}
