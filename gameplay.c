/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 19:01:26 by steh              #+#    #+#             */
/*   Updated: 2022/04/18 10:20:45 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move(t_data *g)
{
	char	*moves;

	animate_player(g);
	if (g->map.maparray[g->player.next_step.y][g->player.next_step.x] == 'C')
		g->map.coin -= 1;
	if ((g->map.maparray[g->player.next_step.y][g->player.next_step.x] == 'E')
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

// move enemy when the next step is space
// replace next step space with enemy
// current step replace with space
// need to automate the movement
int	move_enemy(t_data *g)
{
	static	int	direction_x;
	int			e_y;
	int			e_x;

	e_x = g->enemy.actual.x;
	e_y = g->enemy.actual.y;
	if (direction_x < 0)
	{
		if (g->map.maparray[e_y][e_x - 1] == '1'
			|| g->map.maparray[e_y][e_x - 1] == 'C')
			direction_x = 1;
	}
	else
	{
		direction_x = 1;
		if (g->map.maparray[e_y][e_x + 1] == '1'
			|| g->map.maparray[e_y][e_x + 1] == 'C')
			direction_x = -1;
	}
	g->map.maparray[e_y][e_x + direction_x] = 'G';
	g->map.maparray[e_y][e_x] = '0';
	return (0);
}

void	edit_array(t_data *g)
{
	g->map.maparray[g->player.next_step.y][g->player.next_step.x] = 'P';
	g->map.maparray[g->player.pre_step.y][g->player.pre_step.x] = '0';
}

// after collect coins get, player return to original image
// make coin rotate;
void	animate_player(t_data *g)
{
	if (g->map.maparray[g->player.next_step.y][g->player.next_step.x] == 'C')
		g->image.p = g->image.p2;
	else if (g->map.maparray[g->player.next_step.y][g->player.next_step.x] == '0')
		g->image.p = g->image.tmp;
	}

