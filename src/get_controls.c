/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_controls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 20:36:46 by acrucesp          #+#    #+#             */
/*   Updated: 2021/08/01 17:06:56 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	arrows_move(t_data *data, int k)
{
	if (k == DOWN)
		data->y -= 100;
	else if (k == UP)
		data->y += 100;
	else if (k == LEFT)
		data->x -= 100;
	else if(k == RIGHT)
		data->x += 100;
}

void	zoom(t_data *data, int k)
{
	long long int x_t;

	if (k == 5)	
	{
		data->sfsc.scld_x = data->sfsc.scld_x * 2.0;
		data->sfsc.scld_y = data->sfsc.scld_y * 2.0;
		data->x *= 0.5;
		data->y *= 0.5;
	}
	else if (k == 4)	
	{
		x_t = data->x * 2.0L;	
		if ((data->x >= 0.0L && x_t >= 0.0L) ||
				(data->x <= 0.0L && x_t <= 0.0L))
		{
			data->sfsc.scld_x = data->sfsc.scld_x * 0.5;
			data->sfsc.scld_y = data->sfsc.scld_y * 0.5;
			data->x *= 2.0;
			data->y *= 2.0;
		}
	}
}

void	get_controls (int keycode, t_data *data, char from)
{
	if (from == 'k')
		arrows_move(data, keycode);
	if (from == 'm')	
		zoom(data, keycode);
}
