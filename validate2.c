/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 13:17:17 by steh              #+#    #+#             */
/*   Updated: 2022/04/16 16:03:20 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_newline_eof(char *file, t_map *map)
{
	size_t	i;
	int		fd;
	char	*line;

	i = 0;
	fd = open(file, O_RDONLY);
	while (i < map->row_num - 1)
	{
		line = get_next_line(fd);
		free(line);
		i++;
	}
	line = get_next_line(fd);
	if (ft_strchr(line, '\n'))
		return (FALSE);
	free(line);
	return (TRUE);
}


void	print_error(int errorcode, t_data *g)
{
	(void)g;
	if (errorcode == 1)
		ft_printf("file should be ber");
	else if (errorcode == 2)
		ft_printf("file not valid");
	else if (errorcode == 3)
		ft_printf("map should be rectangular");
	else if (errorcode == 4)
		ft_printf("map invalid size");
	else if (errorcode == 5)
		ft_printf("map should have border");
	else if (errorcode == 6)
		ft_printf("map should have at least one coin");
	else if (errorcode == 7)
		ft_printf("map should have at least one exit");
	else if (errorcode == 8)
		ft_printf("map should have one player only");
	else if (errorcode == 9)
		ft_printf("map contains char other than \"10ECPG\"");
	free_memory(g);
	exit(0);
}

int	map_validity(char *file, t_map *map, t_data *g)
{
	if (!file_is_ber(file, map))
		print_error(1, g);
	else if (map->invalid_file == -1)
		print_error(2, g);
	else if (!map_is_rectangular(file, map))
		print_error(3, g);
	else if (!check_newline_eof(file, map))
		print_error(4, g);
	else if (!map_surround_wall(file, map))
		print_error(5, g);
	map_contains_cep(file, map);
	if (!map->coin)
		print_error(6, g);
	else if (!map->exit)
		print_error(7, g);
	else if (map->player != 1)
		print_error(8, g);
	else if (map->invalid_char > 0)
		print_error(9, g);
	return (1);
}
