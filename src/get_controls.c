/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_controls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 20:36:46 by acrucesp          #+#    #+#             */
/*   Updated: 2021/08/06 00:03:31 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static void	arrows_move(t_data *data, int k)
{
	if (k == (K_MASK | DOWN))
		data->y -= 100;
	else if (k == (K_MASK | UP))
		data->y += 100;
	else if (k == (K_MASK | LEFT))
		data->x += 100;
	else if (k == (K_MASK | RIGHT))
		data->x -= 100;
}

static void	shift_colors(t_data *data, int k)
{
	if (data->c_s > 5 && (k & C_OUT) == C_OUT)
		data->c_s -= 5;
	else if (data->c_s < 250 && (k & C_IN) == C_IN)
		data->c_s += 5;
	else if ((k & I_C) == I_C)
	{
		if (data->i_c)
			data->i_c = 0;
		else
			data->i_c = 1;
	}
}

static void	change_iter(t_data *data, int k)
{
	free(data->colors);
	if ((k == (K_MASK | ITER_MASK | I_IN)) && data->m_iter < 5000)
		data->m_iter += 50;
	if ((k == (K_MASK | ITER_MASK | I_OUT)) && data->m_iter > 100)
		data->m_iter -= 50;
	get_colors(data);
}

static void	zoom(t_data *data, int k)
{
	if ((k == (M_MASK | Z_OUT)) && data->zoom)
	{
		data->zoom--;
		data->sfsc.scld_x = data->sfsc.scld_x * 2.0;
		data->sfsc.scld_y = data->sfsc.scld_y * 2.0;
		data->x *= 0.5;
		data->y *= 0.5;
	}
	else if (k == (M_MASK | Z_IN) && data->zoom < data->lock_zoom)
	{
		data->zoom++;
		data->sfsc.scld_y = data->sfsc.scld_y * 0.5;
		data->y *= 2;
		data->sfsc.scld_x = data->sfsc.scld_x * 0.5;
		data->x *= 2;
	}
}

void	get_controls(int keycode, t_data *data)
{
	if ((keycode & (K_MASK | COLORS_MASK)) == (K_MASK | COLORS_MASK))
		shift_colors(data, keycode);
	else if ((keycode & (K_MASK | ITER_MASK)) == (K_MASK | ITER_MASK))
		change_iter(data, keycode);
	else if ((keycode & K_MASK) == K_MASK)
		arrows_move(data, keycode);
	else if ((keycode & M_MASK) == M_MASK)
		zoom(data, keycode);
}
