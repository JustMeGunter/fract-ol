/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrotSet.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 19:30:40 by acrucesp          #+#    #+#             */
/*   Updated: 2021/08/01 17:47:16 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>


/* Zn = Zn_1^2 + C */ 
int mandelbrot(t_ncomplex *Z, t_ncomplex C, int i, int m_iter) 
{
	long double t;

	if (Z->x * Z->x + Z->y * Z->y <= 4 && i < m_iter)
	{
		t = Z->x * Z->x - Z->y * Z->y + C.x;
		Z->y = 2.0 * Z->x * Z->y + C.y;
		Z->x = t;
		i++;
		return (mandelbrot(Z, C, i, m_iter));
	}
	return (i);
}

void	draw_mandelbrot(t_data *data, int keycode)
{
	int x;
	int y;
	int color;
	int ret;
	t_ncomplex Z;

	x = 0;
	y = 0;
	get_controls(keycode, data, from);
	while (x < WIDTH)
	{
		while(y < HEIGHT)
		{
			reset_values(data, &Z, &color, x, y);
			ret = mandelbrot(&Z, data->C, 0, data->m_iter);
			color = rgb(ret);
			my_mlx_pixel_put(data, x, y, color);
			y++;
		}
		y = 0;
		x++;
	}
}

