/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 12:20:53 by steh              #+#    #+#             */
/*   Updated: 2022/03/28 16:34:24 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(int argc, char *argv[])
{
	// void	*mlx;
	// void	*mlx_win;
	// t_data	img;

	// (void)argv;
	// img.px = 500;
	if (argc != 2)
		ft_putendl_fd("Please use:	./so_long map", 2);
	else if (argc == 2 && map_validity(argv[1]))
	{
		// mlx = mlx_init();
		// mlx_win = mlx_new_window(mlx, 1920, 1080, "So_long!");
		// img.img = mlx_new_image(mlx, 1920, 1080);
		// img.img = mlx_png_file_to_image(mlx, "png/c1.png", &img.px, &img.px);
		// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
		// // mlx_pixel_put(mlx, mlx_win,  250, 250, 0x00FF0000);
		// my_mlx_pixel_put(&img, 25, 25, 0x00FF0000);
		// mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
		// mlx_loop(mlx);
	}
	system("leaks so_long");
	return (0);
}