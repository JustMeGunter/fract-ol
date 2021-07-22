/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 03:15:09 by acrucesp          #+#    #+#             */
/*   Updated: 2021/07/22 22:06:51 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>
#include <stdio.h>
#include <unistd.h>

int	key_hook(int keycode, t_data *data)
{
	(void)data;
	printf("key: %i\n", keycode);
	return (1);
}

int	fncTest(int x, int y)
{
	printf("%i x ,%i y\n", x, y);
	return (0);
}

int	main(void)
{
	t_sfsc		sfsc;
	t_data	data;
	ft_memset(&sfsc, 0, sizeof(t_sfsc));
	get_sfsc(WIDTH, HEIGHT, &sfsc);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "Wololo!!!");
	data.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.size_line, &data.endian);
	
	draw_mandel(&sfsc, &data);
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
	mlx_mouse_hook(data.win, key_hook, &data);
	mlx_hook(data.win, 6, (1L<<6),fncTest, &data);
	mlx_loop(data.mlx);
}
