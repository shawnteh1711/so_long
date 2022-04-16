/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:17:46 by steh              #+#    #+#             */
/*   Updated: 2022/04/16 14:34:30 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_data *g)
{
	if (keycode == ESC)
		close_game(g);
	else if (keycode == LEFT)
		g->player.next_step.x = g->player.pre_step.x - 1;
	else if (keycode == RIGHT)
		g->player.next_step.x = g->player.pre_step.x + 1;
	else if (keycode == UP)
		g->player.next_step.y = g->player.pre_step.y - 1;
	else if (keycode == DOWN)
		g->player.next_step.y = g->player.pre_step.y + 1;
	else
		return (0);
	if (g->map.maparray[g->player.next_step.y][g->player.next_step.x] != '1')
		move(g);
	else
	{
		g->player.next_step.x = g->player.pre_step.x;
		g->player.next_step.y = g->player.pre_step.y;
	}
	return (0);
}

int	close_game(t_data *g)
{
	if (g->map.maparray[g->player.next_step.y][g->player.next_step.x] == 'E'
		&& g->map.coin == 0)
		ft_printf(GREEN "You win!\n");
	else if (g->map.maparray[g->player.next_step.y][g->player.next_step.x] == 'E'
		&& g->map.coin != 0)
		ft_printf(RED "You lose! Coins not all collected!\n");
	else
		ft_printf(RED "You lose!\n");
	mlx_destroy_image(g->mlx, g->image.c);
	mlx_destroy_image(g->mlx, g->image.exit);
	mlx_destroy_image(g->mlx, g->image.g);
	mlx_destroy_image(g->mlx, g->image.p);
	mlx_destroy_image(g->mlx, g->image.w);
	mlx_clear_window(g->mlx, g->win);
	mlx_destroy_window(g->mlx, g->win);
	free(g->mlx);
	// free(g->map.maparray);
	free_array(g);
	// check_leaks();
	// system("leaks so_long");
	exit(0);
	return (0);
}

// 7 leaks
void	free_array(t_data *g)
{
	size_t	i;

	i = 0;
	while (i < g->map.row_num)
		free(g->map.maparray[i++]);
	free(g->map.maparray);
}
