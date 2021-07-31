/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrotSet.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 19:30:40 by acrucesp          #+#    #+#             */
/*   Updated: 2021/07/31 21:01:17 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void reset_values(t_data *data, t_ncomplex *Z, int *color, int x, int y)
{
	*color = 0x00000000; 
	data->C.x = (x - data->x - data->sfsc.shftd_x) * data->sfsc.scld_x;
	data->C.y = (-y + data->y + data->sfsc.shftd_y) * data->sfsc.scld_y;
	ft_memset(Z, 0, sizeof(t_ncomplex));
}

/* Zn = Zn_1^2 + C */ 
int mandelbrot(t_ncomplex *Z, t_ncomplex C, int i) 
{
	long double t;

	if (Z->x * Z->x + Z->y * Z->y <= 4 && i < M_ITER)
	{
		t = Z->x * Z->x - Z->y * Z->y + C.x;
		Z->y = 2.0 * Z->x * Z->y + C.y;
		Z->x = t;
		i++;
		return (mandelbrot(Z, C, i));
	}
	return (i);
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
			reset_values(data, &Z, &color, x, y);
			ret = mandelbrot(&Z, data->C, 0);
			//if (ret > 1)
			color = rgb(ret);
			my_mlx_pixel_put(data, x, y, color);
			y++;
		}
		y = 0;
		x++;
	}
}

