/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrotSet.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 19:30:40 by acrucesp          #+#    #+#             */
/*   Updated: 2021/07/26 19:11:32 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->size_line+ x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	draw_mandel(t_data *data, int k, char t)
{
	int x;
	int y;
	int color;
	int ret;

	x = 0;
	y = 0;
	get_controls(k, data, t);
	while (x < WIDTH)
	{
		while(y < HEIGHT)
		{
			color = 0x00000000; 
			ret = mandel(x,y,data);
			if (ret > 1)
				color = rgb(ret);
			my_mlx_pixel_put(data, x, y, color);
			y++;
		}
		y = 0;
		x++;
	}
}

int mandel(double Px, double Py, t_data *data)
{
	t_cplx cplx;

	ft_memset(&cplx, 0, sizeof(t_cplx));
	cplx.xC = (Px - data->x - data->sfsc.shftd_x) * data->sfsc.scld_x;
	cplx.yC = (-Py + data->y + data->sfsc.shftd_y) * data->sfsc.scld_y;
	while (cplx.x * cplx.x + cplx.y * cplx.y <= 4 && cplx.i < M_ITER)
	{
		cplx.t_x = cplx.x * cplx.x - cplx.y * cplx.y + cplx.xC;
		cplx.y = 2 * cplx.x * cplx.y + cplx.yC;
		cplx.x = cplx.t_x;
		cplx.i++;
	}
	return (cplx.i);
}
