/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 03:15:09 by acrucesp          #+#    #+#             */
/*   Updated: 2021/08/03 13:32:46 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int	key_hook(int keycode, int x, int y, t_data *data)
{
	data->x += (WIDTH * 0.5) - x;
	data->y += (HEIGHT * 0.5) - y;
	data->fractal(data, keycode | M << 8 );
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (1);
}

int	keyboard_hook(int keycode, t_data *data)
{
	if (keycode == ESC)
		exit(0);
	if (((keycode & MASK) == C_IN) || ((keycode & MASK) == C_OUT))
		keycode |= COLORS << 16; 
	else if (((keycode & MASK) == I_IN) || ((keycode & MASK) == I_OUT))
		keycode |= ITER << 16; 
	data->fractal(data, keycode | K << 8);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return(1);
}

int	main(int argc, char **argv)
{
	t_data	data;

	ft_memset(&data, 0, sizeof(t_data));
	parse_args(argc, argv, &data);
	get_sfsc(WIDTH, HEIGHT, &data.sfsc);
	data.m_iter = M_ITER;
	get_colors(&data);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "fract-ol");
	data.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel,
			&data.size_line, &data.endian);
	data.fractal(&data, 0);
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
	mlx_key_hook(data.win, keyboard_hook, &data);
	mlx_mouse_hook(data.win, key_hook, &data);
	mlx_loop(data.mlx);
}
