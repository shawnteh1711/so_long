/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 13:17:17 by steh              #+#    #+#             */
/*   Updated: 2022/03/30 20:55:31 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_validity(char *file, t_map *map)
{
	if (!is_ber(file)
		// || !is_rectangular(file, map)
		// || map_surround_wall(file, map)
		|| !map_contains_cep(file, map)
	)
	{
		ft_printf("error");
		return (0);
	}
	return (1);
}
