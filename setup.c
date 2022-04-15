/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 15:21:34 by steh              #+#    #+#             */
/*   Updated: 2022/04/15 21:05:10 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_map(t_data *g)
{
	void	*(*f)(void *, char *, int *x, int *y);

	f = mlx_png_file_to_image;
	g->image.w = f(g->mlx, "png/barrel.png", &g->map.px, &g->map.px);
	g->image.p = f(g->mlx, "png/pacman.png", &g->map.px, &g->map.px);
	g->image.p2 = f(g->mlx, "png/pacman2.png", &g->map.px, &g->map.px);
	g->image.c = f(g->mlx, "png/c1.png", &g->map.px, &g->map.px);
	g->image.exit = f(g->mlx, "png/portal.png", &g->map.px, &g->map.px);
	g->image.g = f(g->mlx, "png/ghost.png", &g->map.px, &g->map.px);
}

void	put_image(t_data *g)
{
	int	i;
	int	j;
	int	(*f)(void *, void *, void *, int x, int y);

	f = mlx_put_image_to_window;
	i = -1;
	while (++i < (int)g->map.row_num)
	{
		j = -1;
		while (++j < (int)g->map.col_num)
		{
			if (g->map.maparray[i][j] == '1')
				f(g->mlx, g->win, g->image.w, j * g->map.px, i * g->map.px);
			else if (g->map.maparray[i][j] == 'C')
				f(g->mlx, g->win, g->image.c, j * g->map.px, i * g->map.px);
			else if (g->map.maparray[i][j] == 'E')
				f(g->mlx, g->win, g->image.exit, j * g->map.px, i * g->map.px);
			else if (g->map.maparray[i][j] == 'P' && update_player(g, i, j))
				f(g->mlx, g->win, g->image.p, j * g->map.px, i * g->map.px);
			else if (g->map.maparray[i][j] == 'G' && update_enemy(g, i, j))
				f(g->mlx, g->win, g->image.g, j * g->map.px, i * g->map.px);
		}
	}
}

// how to move the player and update the position
int	update_player(t_data *g, int i, int j)
{
	g->player.next_step.x = j;
	g->player.next_step.y = i;
	g->player.pre_step.x = j;
	g->player.pre_step.y = i;
	return (1);
}

int	update_enemy(t_data *g, int i, int j)
{
	g->enemy.actual.x = j;
	g->enemy.actual.y = i;
	return (1);
}

void	init_g(t_data *g)
{
	g->map.coin = 0;
	g->map.player = 0;
	g->map.exit = 0;
	g->map.invalid_char = 0;
	g->map.invalid_file = 0;
}
