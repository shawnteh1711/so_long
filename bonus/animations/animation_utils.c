/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 12:31:00 by steh              #+#    #+#             */
/*   Updated: 2022/04/21 11:10:15 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	destroy_coin_animation(t_data *g)
{
	mlx_destroy_image(g->mlx, g->image.c1);
	mlx_destroy_image(g->mlx, g->image.c2);
}

void	*create_image(t_data *g, char *path)
{
	t_image	img;

	img.ptr = mlx_xpm_file_to_image(g->mlx, path, &g->map.px, &g->map.px);
	return (img.ptr);
}

void	create_coins(t_data *g)
{
	// g->image.c = create_image(g, "png/c1.xpm");
	g->image.c1 = create_image(g, "png/c2.xpm");
	g->image.c2 = create_image(g, "png/c3.xpm");
}

void	render_coin(t_data *g, int i, int j, int type)
{
	int	(*f)(void *, void *, void *, int x, int y);

	f = mlx_put_image_to_window;
	create_coins(g);
	if (type == 1)
		f(g->mlx, g->win, g->image.c, j * g->map.px, i * g->map.px);
	if (type == 2)
		f(g->mlx, g->win, g->image.c1, j * g->map.px, i * g->map.px);
	if (type == 3)
		f(g->mlx, g->win, g->image.c2, j * g->map.px, i * g->map.px);
	if (type == 4)
		f(g->mlx, g->win, g->image.c, j * g->map.px, i * g->map.px);
	if (type == 5)
		f(g->mlx, g->win, g->image.c1, j * g->map.px, i * g->map.px);
	if (type == 6)
		f(g->mlx, g->win, g->image.c2, j * g->map.px, i * g->map.px);
}

int	animate(t_data *g)
{
	static int	frame;
	frame++;
	if (frame < 10)
		put_image(g, 1);
	else if (frame < 20)
		put_image(g, 2);
	else if (frame < 30)
		put_image(g, 3);
	else if (frame < 40)
		put_image(g, 4);
	else if (frame < 50)
		put_image(g, 5);
	else if (frame > 50)
	{
		put_image(g, 6);
		frame = 0;
	}
	return (0);
}
