/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 10:17:15 by steh              #+#    #+#             */
/*   Updated: 2022/04/21 09:43:54 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_rectangular(t_map *map, char *line, int fd)
{
	map->is_rect = TRUE;
	while (line)
	{
		if (ft_strlen2(line) != map->col_num)
			map->is_rect = FALSE;
		free(line);
		line = get_next_line(fd);
		map->row_num++;
	}
	if (map->is_rect == FALSE)
		return (FALSE);
	return (TRUE);
}

void	render_image(t_data *g, int i, int j, int *k)
{
	int		(*f)(void *, void *, void *, int x, int y);

	f = mlx_put_image_to_window;
	if (g->map.maparray[i][j] == '1')
		f(g->mlx, g->win, g->image.w, j * g->map.px, i * g->map.px);
	else if (g->map.maparray[i][j] == 'C')
		f(g->mlx, g->win, g->image.c, j * g->map.px, i * g->map.px);
	else if (g->map.maparray[i][j] == 'E')
		f(g->mlx, g->win, g->image.exit, j * g->map.px, i * g->map.px);
	else if (g->map.maparray[i][j] == 'P' && update_player(g, i, j))
		f(g->mlx, g->win, g->image.p, j * g->map.px, i * g->map.px);
	else if (g->map.maparray[i][j] == 'G' && update_enemy(g, i, j, ++(*k)))
		f(g->mlx, g->win, g->image.g, j * g->map.px, i * g->map.px);
}
