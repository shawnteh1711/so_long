/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 19:01:26 by steh              #+#    #+#             */
/*   Updated: 2022/04/15 21:16:41 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move(t_data *g)
{
	char	*moves;

	move_enemy(g);
	if (g->map.maparray[g->player.next_step.y][g->player.next_step.x] == 'C')
		g->map.coin -= 1;
	animate(g);
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
}

// move enemy when the next step is space
// replace next step space with enemy
// current step replace with space
// need to automate the movement
void	move_enemy(t_data *g)
{
	int	i;
	int	y;
	int	k;
	int	e_y;
	int	e_x;

	i = 0;
	
	e_y = g->enemy.actual.y;
	e_x = g->enemy.actual.x;
	y = 0;
	k = 0;
	while (i < 100)
	{
		if (g->map.maparray[e_y][e_x - 1] != '1')
		{
			g->map.maparray[e_y][e_x - 1] = 'G';
			g->map.maparray[e_y][e_x] = '0';
			ft_printf("y:%d\n", y);
			y++;
		}
		else
		{
			if (k < y && g->map.maparray[e_y][e_x + 1] != '1')
			{
				g->map.maparray[e_y][e_x + 1] = 'G';
				g->map.maparray[e_y][e_x] = '0';
				ft_printf("k:%d\n", k);
				k++;
			}
		}
		i++;
	}
}

void	edit_array(t_data *g)
{
	g->map.maparray[g->player.next_step.y][g->player.next_step.x] = 'P';
	g->map.maparray[g->player.pre_step.y][g->player.pre_step.x] = '0';
}

// after collect coins get, player return to original image
// make coin rotate;
void	animate(t_data *g)
{
	void	*tmp;

	tmp = g->image.p;
	if (g->map.maparray[g->player.next_step.y][g->player.next_step.x] == 'C')
		g->image.p = g->image.p2;
	if (g->map.maparray[g->player.next_step.y][g->player.next_step.x] == '0')
		g->image.p = tmp;
}
