/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 13:17:17 by steh              #+#    #+#             */
/*   Updated: 2022/04/21 11:34:20 by steh             ###   ########.fr       */
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

void	print_error2(int errorcode, t_data *g)
{
	if (errorcode == 5)
		ft_printf("Error. Map need min one coin\n");
	else if (errorcode == 6)
		ft_printf("Error. Map need min exit\n");
	else if (errorcode == 7)
		ft_printf("Error. Map need one player only\n");
	else if (errorcode == 8)
		ft_printf("Error. Map have other char than \"10ECPG\"\n");
	free_memory_invalid_file(g);
	exit(0);
}

void	print_error(int errorcode, t_data *g)
{
	if (errorcode == 1)
	{
		if (g->map.invalid_file == -1)
			ft_printf("Error. File not valid\n");
		else
			ft_printf("Error. File should be ber\n");
	}
	else if (errorcode == 2)
	{
		if (g->map.empty_file == -1)
			ft_printf("Error. Map is empty\n");
		else if (g->map.is_rect == FALSE)
			ft_printf("Error. Map not rectangular\n");
	}
	else if (errorcode == 3)
		ft_printf("Error. Map invalid size\n");
	else if (errorcode == 4)
		ft_printf("Error. Map is not border\n");
	print_error2(errorcode, g);
}

int	map_validity(char *file, t_map *map, t_data *g)
{
	if (!file_is_ber(file, map))
		print_error(1, g);
	else if (!map_is_rectangular(file, map))
		print_error(2, g);
	else if (!check_newline_eof(file, map))
		print_error(3, g);
	else if (!map_surround_wall(file, map))
		print_error(4, g);
	map_contains_cep(file, map);
	if (!map->coin)
		print_error(5, g);
	else if (!map->exit)
		print_error(6, g);
	else if (map->player != 1)
		print_error(7, g);
	else if (map->invalid_char > 0)
		print_error(8, g);
	return (1);
}
