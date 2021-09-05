/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   juliaSet.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   created: 2021/07/27 21:13:36 by acrucesp          #+#    #+#             */
/*   Updated: 2021/08/05 13:24:18 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static void	reset_values(t_data *data, t_ncomplex *z, int x, int y)
{
	data->b_color = 0x00000000;
	z->x = (x - data->x - data->sfsc.shftd_x) * data->sfsc.scld_x;
	z->y = (-y + data->y + data->sfsc.shftd_y) * data->sfsc.scld_y;
}

/* z_0 = x + yi 	*/
/* zn = zn_1^2 + c 	*/
static int	julia(t_ncomplex *z, t_ncomplex c, int i, int m_iter)
{
	long double	t;

	if (z->x * z->x + z->y * z->y <= 4 && i < m_iter)
	{
		t = z->x * z->x - z->y * z->y + c.x;
		z->y = 2.0 * z->x * z->y + c.y;
		z->x = t;
		i++;
		return (julia(z, c, i, m_iter));
	}
	return (i);
}

void	draw_julia(t_data *data, int keycode)
{
	int			x;
	int			y;
	int			ret;
	t_ncomplex	z;

	x = 0;
	y = 0;
	get_controls(keycode, data);
	while (x < WIDTH)
	{
		while (y < HEIGHT)
		{
			reset_values(data, &z, x, y);
			ret = julia(&z, data->c, 0, data->m_iter);
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
