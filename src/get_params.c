/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 20:22:12 by acrucesp          #+#    #+#             */
/*   Updated: 2021/08/05 23:13:08 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	get_sfsc(int x, int y, t_sfsc *sfsc)
{
	sfsc->shftd_x = x / 2.0;
	sfsc->shftd_y = y / 2.0;
	sfsc->scld_x = 4.0 / x;
	sfsc->scld_y = 4.0 / y;
}

void	load_data(t_data *data, int argc, char **argv)
{
	data->lock_zoom = 50;
	parse_args(argc, argv, data);
	get_sfsc(WIDTH, HEIGHT, &data->sfsc);
	data->m_iter = M_ITER;
	data->c_s = 255;
	data->b_color = 0x00000000;
	data->i_c = 1;
	get_colors(data);
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "fract-ol");
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->size_line, &data->endian);
}
