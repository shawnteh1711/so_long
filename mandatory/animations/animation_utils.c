/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 12:31:00 by steh              #+#    #+#             */
/*   Updated: 2022/04/21 09:45:01 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	*create_image(t_data *g, char *path)
{
	t_image	img;

	img.ptr = mlx_xpm_file_to_image(g->mlx, path, &g->map.px, &g->map.px);
	return (img.ptr);
}

void	create_coins(t_data *g)
{
	g->image.c = create_image(g, "png/c1.xpm");
	g->image.c1 = create_image(g, "png/ghost.xpm");
	g->image.c2 = create_image(g, "png/barrel.xpm");
	ft_printf("Create coins\n");
}

void	render_coin(t_data *g, int i, int j, int type)
{
	int	(*f)(void *, void *, void *, int x, int y);

	f = mlx_put_image_to_window;
	create_coins(g);
	if (type == 0)
	{
		ft_printf("1\n");
		f(g->mlx, g->win, g->image.c, j * g->map.px, i * g->map.px);
	}
	if (type == 1)
	{
		ft_printf("1\n");
		f(g->mlx, g->win, g->image.c1, j * g->map.px, i * g->map.px);
	}
	if (type == 2)
	{
		ft_printf("1\n");
		f(g->mlx, g->win, g->image.c2, j * g->map.px, i * g->map.px);
	}
}

int	animate(t_data *g)
{
	static int	frame;
	frame++;
	ft_printf("frame: %d\n", frame);
	if (frame < 5)
	{
		ft_printf("frame < 5: %d\n", frame);
		put_image(g);
	}
	else if (frame < 10)
	{
		ft_printf("frame < 5: %d\n", frame);
		put_image(g);
	}
	else if (frame < 15)
	{
		put_image(g);
		ft_printf("frame end: %d\n", frame);
	}
	frame = 0;
	return (0);
}
