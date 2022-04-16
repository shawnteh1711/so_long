/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 12:31:00 by steh              #+#    #+#             */
/*   Updated: 2022/04/16 14:28:31 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	render_coin(t_data *g, int i, int j, int type)
{
	int	(*f)(void *, void *, void *, int x, int y);

	f = mlx_put_image_to_window;
	if (type == 0)
		f(g->mlx, g->win, g->image.c, j * g->map.px, i * g->map.px);
	if (type == 1)
		f(g->mlx, g->win, g->image.c1, j * g->map.px, i * g->map.px);
	if (type == 2)
		f(g->mlx, g->win, g->image.c2, j * g->map.px, i * g->map.px);
}

int	animate(t_data *g)
{
	g->frame++;
	if (g->frame < 10)
		put_image(g);
	else if (g->frame < 20)
		put_image(g);
	else if (g->frame < 30)
		put_image(g);
	g->frame = 0;
	return (0);
}