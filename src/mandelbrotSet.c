/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrotSet.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 19:30:40 by acrucesp          #+#    #+#             */
/*   Updated: 2021/07/28 22:28:09 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void reset_values(t_data *data, t_ncomplex *Z, int color, int x, int y)
{
	color = 0x00000000; 
	data->i = 0;
	data->C.x = (x - data->x - data->sfsc.shftd_x) * data->sfsc.scld_x;
	data->C.y = (-y + data->y + data->sfsc.shftd_y) * data->sfsc.scld_y;
	ft_memset(&Z, 0, sizeof(t_ncomplex));
}

/* Zn = Zn_1^2 + C */ 
int mandelbrot(t_ncomplex *Z, t_data *data)
{
	if (Z->x * Z->x + Z->y * Z->y <= 4 && data->i < M_ITER)
	{
		pow_complex(*Z, Z);
		add_complex(*Z, data->C, Z); 
		data->i++;
		return (mandelbrot(Z, data));
	}
	return (data->i);
}

void	draw_mandelbrot(t_data *data, char k, char t)
{
	int x;
	int y;
	int color;
	int ret;
	t_ncomplex Z;

	x = 0;
	y = 0;
	get_controls(k, data, t);
	while (x < WIDTH)
	{
		while(y < HEIGHT)
		{
			reset_values(data, &Z, color, x, y);
			ret = mandelbrot(&Z ,data);
			if (ret > 1)
				color = rgb(ret);
			my_mlx_pixel_put(data, x, y, color);
			y++;
		}
		y = 0;
		x++;
	}
}

