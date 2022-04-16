/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 12:20:53 by steh              #+#    #+#             */
/*   Updated: 2022/04/16 14:42:09 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_g(t_data *g)
{
	g->map.coin = 0;
	g->map.player = 0;
	g->map.exit = 0;
	g->frame = 0;
	g->map.invalid_char = 0;
	g->map.invalid_file = 0;
}

int	main(int argc, char *argv[])
{
	t_data	g;

	g.px = 128;
	init_g(&g);
	if (argc != 2)
		ft_printf("Please use:	./so_long map.ber\n");
	else if (argc == 2 && map_validity(argv[1], &g.map))
	{
		g.mlx = mlx_init();
		g.win = mlx_new_window(g.mlx, g.map.col_num * g.px,
				g.map.row_num * g.px, "So_long - shawn");
		init_map(&g);
		put_image(&g);
		mlx_hook(g.win, 17, 0, close_game, &g);
		mlx_key_hook(g.win, key_hook, &g);
		// mlx_loop_hook(g.win, put_image, &g);
		// mlx_loop_hook(g.win, move_enemy, &g);
		// mlx_loop_hook(g.win, animate, &g);
		mlx_loop(g.mlx);
	}
	return (0);
}
