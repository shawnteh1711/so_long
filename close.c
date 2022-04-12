/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:17:46 by steh              #+#    #+#             */
/*   Updated: 2022/04/12 20:11:06 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_data *g)
{
	if (keycode == ESC)
		close_game(g);
	else if (keycode == LEFT)
		g->player.attempt.x = g->player.actual.x - 1;
	else if (keycode == RIGHT)
		g->player.attempt.x = g->player.actual.x + 1;
	else if (keycode == UP)
		g->player.attempt.y = g->player.actual.y - 1;
	else if (keycode == DOWN)
		g->player.attempt.y = g->player.actual.y + 1;
	return (0);
}

int	close_game(t_data *g)
{
	mlx_destroy_window(g->mlx, g->win);
	free_array(g);
	exit(0);
}

void	free_array(t_data *g)
{
	size_t	i;

	i = 0;
	while (i < g->map.row_num)
		free(g->map.maparray[i++]);
}
