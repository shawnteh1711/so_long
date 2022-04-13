/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 13:17:17 by steh              #+#    #+#             */
/*   Updated: 2022/04/13 18:32:55 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_error(int errorcode)
{
	if (errorcode == 1)
		ft_printf("file should be ber");
	else if (errorcode == 2)
		ft_printf("file not valid");
	else if (errorcode == 3)
		ft_printf("map should be rectangular");
	else if (errorcode == 4)
		ft_printf("map should have border");
	else if (errorcode == 5)
		ft_printf("map should have at least one coin");
	else if (errorcode == 6)
		ft_printf("map should have at least one exit");
	else if (errorcode == 7)
		ft_printf("map should have one player only");
	else if (errorcode == 8)
		ft_printf("map contains char other than \"10ECPG\"");
	
	exit(0);
}

int	map_validity(char *file, t_map *map)
{
	if (!file_is_ber(file, map))
		print_error(1);
	else if (map->invalid_file == -1)
		print_error(2);
	else if (!map_is_rectangular(file, map))
		print_error(3);
	else if (!map_surround_wall(file, map))
		print_error(4);
	map_contains_cep(file, map);
	if (!map->coin)
		print_error(5);
	else if (!map->exit)
		print_error(6);
	else if (map->player != 1)
		print_error(7);
	else if (map->invalid_char > 0)
		print_error(8);
	
	return (1);
}
