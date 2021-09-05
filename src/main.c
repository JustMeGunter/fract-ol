/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 03:15:09 by acrucesp          #+#    #+#             */
/*   Updated: 2021/09/05 19:50:45 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static int	key_hook(int keycode, int x, int y, t_data *data)
{
	get_colors(data);
	data->x += (WIDTH * 0.5) - x;
	data->y += (HEIGHT * 0.5) - y;
	data->fractal(data, keycode | M << 8 );
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	free(data->colors);
	return (1);
}

static int	keyboard_hook(int keycode, t_data *data)
{
	if (keycode == ESC)
		exit(0);
	get_colors(data);
	if (((keycode & MASK) == C_IN) || ((keycode & MASK) == C_OUT)
		|| ((keycode & MASK) == I_C))
		keycode |= COLORS << 16;
	else if (((keycode & MASK) == I_IN) || ((keycode & MASK) == I_OUT))
		keycode |= ITER << 16;
	data->fractal(data, keycode | K << 8);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	free(data->colors);
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	data;

	ft_memset(&data, 0, sizeof(t_data));
	load_data(&data, argc, argv);
	data.fractal(&data, 0);
	free(data.colors);
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
	mlx_key_hook(data.win, keyboard_hook, &data);
	mlx_mouse_hook(data.win, key_hook, &data);
	mlx_loop(data.mlx);
}
