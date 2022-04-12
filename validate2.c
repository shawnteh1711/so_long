/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 13:17:17 by steh              #+#    #+#             */
/*   Updated: 2022/04/12 14:28:15 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_validity(char *file, t_map *map)
{
	if (!file_is_ber(file))
		ft_printf("file should be ber");
	else if (!map_is_rectangular(file, map))
		ft_printf("map should be rectangular");
	else if (!map_surround_wall(file, map))
		ft_printf("map should have border");
	else if (!map_contains_cep(file, map))
		ft_printf("map should have one player, exit, collectives");
	return (1);
}
