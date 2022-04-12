/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 15:21:34 by steh              #+#    #+#             */
/*   Updated: 2022/04/12 20:51:12 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_map(t_data *g)
{
	void *(*f)(void *, char *, int *x, int *y);

	f = mlx_png_file_to_image;
	g->image.w = f(g->mlx, "png/barrel.png", &g->map.px, &g->map.px);
	g->image.p = f(g->mlx, "png/pacman.png", &g->map.px, &g->map.px);
	g->image.c = f(g->mlx, "png/c1.png", &g->map.px, &g->map.px);
	g->image.exit = f(g->mlx, "png/portal.png", &g->map.px, &g->map.px);
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
			else if (g->map.maparray[i][j] == 'P' && update_p(g, i, j))
				f(g->mlx, g->win, g->image.p, j * g->map.px, i * g->map.px);
		}
	}
}

// how to move the player and update the position
int	update_p(t_data *g, int i, int j)
{
	g->player.attempt.x = j;
	g->player.attempt.y = i;
	g->player.actual.x = j;
	g->player.actual.y = i;
	return (1);
}
