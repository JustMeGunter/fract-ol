/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 03:15:09 by acrucesp          #+#    #+#             */
/*   Updated: 2021/07/15 22:35:30 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}


int	main(void)
{
	void		*mlx;
	void		*mlx_win;
	t_sfsc		sfsc;
	int x = 0;
	int y = 0;
	t_data	img;
	int color = 0x00FF0000; 
	int ret;

	ft_memset(&sfsc, 0, sizeof(t_sfsc));
	get_sfsc(WIDTH, HEIGHT, &sfsc);
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, WIDTH, HEIGHT, "Wololo!!!");
	img.img = mlx_new_image(mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	while (x < WIDTH)
	{
		while(y < HEIGHT)
		{
			ret = mandel(x,y,&sfsc);
			if (ret > 50)
				color = 0x00000000;
			else
				color = 0x00FF0000; 
			my_mlx_pixel_put(&img, x, y, color);
			y++;
		}
		y = 0;
		x++;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
