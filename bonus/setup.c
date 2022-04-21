/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 15:21:34 by steh              #+#    #+#             */
/*   Updated: 2022/04/21 11:27:47 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_map(t_data *g)
{
	void	*(*f)(void *, char *, int *x, int *y);

	f = mlx_xpm_file_to_image;
	g->image.w = f(g->mlx, "png/barrel.xpm", &g->map.px, &g->map.px);
	g->image.p = f(g->mlx, "png/pacman.xpm", &g->map.px, &g->map.px);
	g->image.p2 = f(g->mlx, "png/pacman2.xpm", &g->map.px, &g->map.px);
	g->image.c = f(g->mlx, "png/c1.xpm", &g->map.px, &g->map.px);
	g->image.exit = f(g->mlx, "png/portal.xpm", &g->map.px, &g->map.px);
	g->image.g = f(g->mlx, "png/ghost.xpm", &g->map.px, &g->map.px);
	g->image.tmp = f(g->mlx, "png/pacman.xpm", &g->map.px, &g->map.px);
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

void	init_enemies(t_data *g)
{
	t_enemy	*enemies;

	enemies = malloc(sizeof(t_enemy) * g->map.enemy);
	if (!enemies)
		return ;
	g->enemies = enemies;
}

int	update_enemy(t_data *g, int i, int j, int k)
{
	if (k > 0)
	{
		g->enemies[k].actual.x = j;
		g->enemies[k].actual.y = i;
	}
	g->map.enemy = k;
	return (1);
}

int	put_image(t_data *g, int type)
{
	size_t	i;
	size_t	j;
	int		k;
	char	*moves;

	i = 0;
	j = 0;
	k = 0;
	while (i < g->map.row_num)
	{
		j = 0;
		while (j < g->map.col_num)
		{
			render_image(g, i, j, type);
			if (g->map.maparray[i][j] == 'G' && update_enemy(g, i, j, ++k))
				mlx_put_image_to_window
				(g->mlx, g->win, g->image.g, j * g->map.px, i * g->map.px);
			j++;
		}
		i++;
	}
	moves = ft_itoa(g->player.moves);
	mlx_string_put(g->mlx, g->win, 40, 40, 0x00FFFFFF, moves);
	free(moves);
	return (0);
}
