/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 19:01:26 by steh              #+#    #+#             */
/*   Updated: 2022/04/21 10:48:22 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move(t_data *g)
{
	char	*moves;

	animate_player(g);
	move_enemy(g);
	if (g->map.maparray[g->player.next_step.y][g->player.next_step.x] == 'E'
		&& g->map.coin != 0)
	{
		g->player.next_step.x = g->player.pre_step.x;
		g->player.next_step.y = g->player.pre_step.y;
		return (0);
	}
	if ((g->map.maparray[g->player.next_step.y][g->player.next_step.x] == 'E'
		&& g->map.coin == 0)
		|| g->map.maparray[g->player.next_step.y][g->player.next_step.x] == 'G')
		close_game(g);
	g->player.moves += 1;
	edit_array(g);
	mlx_clear_window(g->mlx, g->win);
	put_image(g);
	moves = ft_itoa(g->player.moves);
	mlx_string_put(g->mlx, g->win, 40, 40, 0x00FFFFFF, moves);
	free(moves);
	return (0);
}

int	change_direction(t_data *g, int e_y, int e_x, int d_x)
{
	if (g->map.maparray[e_y][e_x + 1] == '0')
		d_x = 1;
	if (g->map.maparray[e_y][e_x - 1] == '0')
		d_x = -1;
	if (g->map.maparray[e_y][e_x - 1] != '0'
		&& g->map.maparray[e_y][e_x + 1] != '0')
		d_x = 0;
	return (d_x);
}

// move enemy when the next step is space
// replace next step space with enemy
// current step replace with space
// need to automate the movement
int	move_enemy(t_data *g)
{
	static int	direction_x;
	int			e_y;
	int			e_x;
	int			k;

	k = 0;
	while (k++ < g->map.enemy)
	{
		e_y = g->enemies[k].actual.y;
		e_x = g->enemies[k].actual.x;
		direction_x = change_direction(g, e_y, e_x, direction_x);
		if (direction_x != 0)
		{
			g->map.maparray[e_y][e_x + direction_x] = 'G';
			g->map.maparray[e_y][e_x] = '0';
		}
	}
	return (0);
}

void	edit_array(t_data *g)
{
	g->map.maparray[g->player.next_step.y][g->player.next_step.x] = 'P';
	g->map.maparray[g->player.pre_step.y][g->player.pre_step.x] = '0';
}

// after collect coins get, player return to original image
void	animate_player(t_data *g)
{
	int		y;
	int		x;

	y = g->player.next_step.y;
	x = g->player.next_step.x;
	if (g->map.maparray[y][x] == 'C')
		g->image.p = g->image.p2;
	else if (g->map.maparray[y][x] == '0')
		g->image.p = g->image.tmp;
}
