/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 17:53:22 by acrucesp          #+#    #+#             */
/*   Updated: 2021/08/05 18:00:37 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static void	reset_values(t_data *data, t_ncomplex *Z, int x, int y)
{
	data->b_color = 0x00000000;
	data->C.x = (x - data->x - data->sfsc.shftd_x) * data->sfsc.scld_x;
	data->C.y = (-y + data->y + data->sfsc.shftd_y) * data->sfsc.scld_y;
	ft_memset(Z, 0, sizeof(t_ncomplex));
}

/* Z_0 = 0			*/
/* Zn = Zn_1^3 + C 	*/
static int	bonus(t_ncomplex *Z, t_ncomplex C, int i, int m_iter)
{
	long double	t;

	if (Z->x * Z->x + Z->y * Z->y <= 4 && i < m_iter)
	{
		t = (Z->x * Z->x * Z->x) - (3.0L * Z->x * (Z->y * Z->y)) + C.x;
		Z->y = (3.0L * (Z->x * Z->x) * Z->y) - (Z->y * Z->y * Z->y) + C.y;
		Z->x = t;
		i++;
		return (bonus(Z, C, i, m_iter));
	}
	return (i);
}

void	draw_bonus_b(t_data *data, int keycode)
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
			ret = bonus(&Z, data->C, 0, data->m_iter);
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
