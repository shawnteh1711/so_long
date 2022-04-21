/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:17:46 by steh              #+#    #+#             */
/*   Updated: 2022/04/21 10:51:12 by steh             ###   ########.fr       */
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
	if (g->map.maparray[g->player.next_step.y][g->player.next_step.x] == 'C')
		g->map.coin -= 1;
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
	int		y;
	int		x;

	y = g->player.next_step.y;
	x = g->player.next_step.x;
	if (g->map.maparray[y][x] == 'E'
		&& g->map.coin == 0)
		ft_printf(GREEN "You win!\n");
	else
		ft_printf(RED "You lose!\n");
	free_memory(g);
	return (0);
}

void	free_memory(t_data *g)
{
	size_t	i;

	i = 0;
	while (i < g->map.row_num)
	{
		free(g->map.maparray[i]);
		i++;
	}
	free(g->map.maparray);
	if (g->enemies)
	{
		free(g->enemies);
		mlx_destroy_image(g->mlx, g->image.g);
	}
	mlx_destroy_image(g->mlx, g->image.w);
	mlx_destroy_image(g->mlx, g->image.p);
	mlx_destroy_image(g->mlx, g->image.c);
	mlx_destroy_image(g->mlx, g->image.exit);
	mlx_clear_window(g->mlx, g->win);
	mlx_destroy_window(g->mlx, g->win);
	exit(0);
}

void	free_memory_invalid_file(t_data *g)
{
	size_t	i;

	i = 0;
	if (g->map.row_num != 0 && g->map.is_rect != FALSE
		&& g->map.invalid_size == -1)
	{
		while (i < g->map.row_num)
		{
			if (g->map.maparray)
				free(g->map.maparray[i]);
			i++;
		}
		free(g->map.maparray);
	}
}
