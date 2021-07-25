/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 03:15:09 by acrucesp          #+#    #+#             */
/*   Updated: 2021/07/25 06:15:58 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int	key_hook(int keycode, int x, int y, t_data *data)
{
	//if (keycode == 4)
	//{
	//	data->x += x;
	//	data->y += y;
	//}
	//else if (keycode == 5)
	//{
	//	data->x -= x;
	//	data->y -= y;
	//}
	draw_mandel(data, keycode, 'm');
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	printf("key pass: %i\n x:%i y:%i\n", keycode, x, y);
	return (1);
}

int	keyboard_hook(int keycode, t_data *data)
{
	printf("key: %i\n", keycode);
	draw_mandel(data, keycode, 'k');
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return(1);
}

//int	fncTest(int x, int y)
//{
//	printf("%i x ,%i y\n", x, y);
//	return (0);
//}

int	main(void)
{
	t_data	data;

	data.x = 0;
	data.y = 0;
	ft_memset(&data, 0, sizeof(t_data));
	get_sfsc(WIDTH, HEIGHT, &data.sfsc);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "Wololo!!!");
	data.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.size_line, &data.endian);
	
	draw_mandel(&data, 0, 0);
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);

	mlx_key_hook(data.win, keyboard_hook, &data);
	mlx_mouse_hook(data.win, key_hook, &data);
	//mlx_hook(data.win, 6, (1L<<6),fncTest, &data);

	mlx_loop(data.mlx);
}
