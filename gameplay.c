/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 19:01:26 by steh              #+#    #+#             */
/*   Updated: 2022/04/13 20:43:54 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move(t_data *g)
{
	char	*moves;
	char	*message;

	if (g->map.maparray[g->player.next_step.y][g->player.next_step.x] == 'C')
		g->map.coin -= 1; 
	if ((g->map.maparray[g->player.next_step.y][g->player.next_step.x] == 'E'
		&& g->map.coin == 0) 
		|| g->map.maparray[g->player.next_step.y][g->player.next_step.x] == 'G')
		close_game(g);
	else if (g->map.maparray[g->player.next_step.y][g->player.next_step.x] == 'E')
	{
		message = "Please collect all coins";
		mlx_string_put(g->mlx, g->win, 100, 100, 0x00FFFFFF, message);
	} 
	g->player.moves += 1;
	edit_array(g);
	mlx_clear_window(g->mlx, g->win);
	put_image(g);
	moves = ft_itoa(g->player.moves);
	mlx_string_put(g->mlx, g->win, 40, 40, 0x00FFFFFF, moves);
	free(moves);
}

void	edit_array(t_data *g)
{
	g->map.maparray[g->player.next_step.y][g->player.next_step.x] = 'P';
	g->map.maparray[g->player.pre_step.y][g->player.pre_step.x] = '0';
}
