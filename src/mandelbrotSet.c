/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrotSet.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 19:30:40 by acrucesp          #+#    #+#             */
/*   Updated: 2021/07/22 22:14:04 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->size_line+ x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	draw_mandel(t_sfsc *sfsc, t_data *data)
{
	int x;
	int y;
	int color;
	int ret;

	x = 0;
	y = 0;
	while (x < WIDTH)
	{
		while(y < HEIGHT)
		{
			color = 0x00FF0000; 
			ret = mandel(x,y,sfsc);
			if (ret > 1)
				color = rgb(ret);
			my_mlx_pixel_put(data, x, y, color);
			y++;
		}
		y = 0;
		x++;
	}
}

int mandel(double Px, double Py, t_sfsc *sfsc)
{
	t_cplx cplx;
	int aX;
	int aY;

	//generar dos acumuladores para x e y /2 
	aX = 0;
	aY = 0;
	ft_memset(&cplx, 0, sizeof(t_cplx));
	cplx.xC = (Px - aX - sfsc->shftd_x) * sfsc->scld_x;
	cplx.yC = (-Py + aY + sfsc->shftd_y) * sfsc->scld_y;
	while (cplx.x * cplx.x + cplx.y * cplx.y <= 4 && cplx.i < M_ITER)
	{
		cplx.t_x = cplx.x * cplx.x - cplx.y * cplx.y + cplx.xC;
		cplx.y = 2 * cplx.x * cplx.y + cplx.yC;
		cplx.x = cplx.t_x;
		cplx.i++;
	}
	return (cplx.i);
}
