/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:17:46 by steh              #+#    #+#             */
/*   Updated: 2022/04/13 19:02:46 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_data *g)
{
	if (keycode == ESC)
		close_game(g);
	else if (keycode == LEFT)
		g->player.next_step.x = g->player.next_step.x - 1;
	else if (keycode == RIGHT)
		g->player.next_step.x = g->player.next_step.x + 1;
	else if (keycode == UP)
		g->player.next_step.y = g->player.next_step.y - 1;
	else if (keycode == DOWN)
		g->player.next_step.y = g->player.next_step.y + 1;
	else
		return (0);
	if (keycode == LEFT || keycode == RIGHT
		|| keycode == UP || keycode == DOWN)
		g->player.moves += 1;
	if (g->map.maparray[g->player.next_step.y][g->player.next_step.x] != '1')
		move(g);
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
