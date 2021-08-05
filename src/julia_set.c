/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   juliaSet.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 21:13:36 by acrucesp          #+#    #+#             */
/*   Updated: 2021/08/05 13:24:18 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static void	reset_values(t_data *data, t_ncomplex *Z, int x, int y)
{
	data->b_color = 0x00000000;
	Z->x = (x - data->x - data->sfsc.shftd_x) * data->sfsc.scld_x;
	Z->y = (-y + data->y + data->sfsc.shftd_y) * data->sfsc.scld_y;
}

/* Z_0 = x + yi 	*/
/* Zn = Zn_1^2 + C 	*/
static int	julia(t_ncomplex *Z, t_ncomplex C, int i, int m_iter)
{
	long double	t;

	if (Z->x * Z->x + Z->y * Z->y <= 4 && i < m_iter)
	{
		t = Z->x * Z->x - Z->y * Z->y + C.x;
		Z->y = 2.0 * Z->x * Z->y + C.y;
		Z->x = t;
		i++;
		return (julia(Z, C, i, m_iter));
	}
	return (i);
}

void	draw_julia(t_data *data, int keycode)
{
	int			x;
	int			y;
	int			ret;
	t_ncomplex	Z;

	x = 0;
	y = 0;
	get_controls(keycode, data);
	while (x < WIDTH)
	{
		while (y < HEIGHT)
		{
			reset_values(data, &Z, x, y);
			ret = julia(&Z, data->C, 0, data->m_iter);
			if (ret < (data->m_iter - 1) && !data->i_c)
				data->b_color = 0x00FFFFFF - data->colors[ret];
			else if (ret < (data->m_iter - 1) && data->i_c)
				data->b_color = data->colors[ret];
			my_mlx_pixel_put(data, x, y, data->b_color);
			y++;
		}
		y = 0;
		x++;
	}
}
