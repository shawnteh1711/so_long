/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 12:20:53 by steh              #+#    #+#             */
/*   Updated: 2022/04/19 17:28:26 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_g(t_data *g)
{
	g->frame = 0;
	g->map.coin = 0;
	g->map.player = 0;
	g->map.exit = 0;
	g->map.enemy = 0;
	g->map.row_num = 0;
	g->map.col_num = 0;
	g->map.invalid_char = 0;
	g->map.invalid_file = 0;
	g->map.empty_file = 0;
	g->px = 64;
}

int	main(int argc, char *argv[])
{
	t_data	g;

	init_g(&g);
	if (argc == 2 && map_validity(argv[1], &g.map, &g))
	{
		g.mlx = mlx_init();
		g.win = mlx_new_window(g.mlx, g.map.col_num * g.px,
				g.map.row_num * g.px, "So_long - shawn");
		init_map(&g);
		init_enemies(&g);
		put_image(&g);
		mlx_hook(g.win, 17, 0, close_game, &g);
		mlx_key_hook(g.win, key_hook, &g);
		mlx_loop(g.mlx);
	}
	else
		ft_printf("Please use:	./so_long map.ber\n");
	return (0);
}
