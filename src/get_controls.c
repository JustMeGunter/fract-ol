/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_controls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 20:36:46 by acrucesp          #+#    #+#             */
/*   Updated: 2021/08/01 19:22:03 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	arrows_move(t_data *data, int k)
{
	if ((k & DOWN) == DOWN)
		data->y -= 100;
	else if ((k & UP) == UP)
		data->y += 100;
	else if ((k & LEFT) == LEFT)
		data->x += 100;
	else if((k & RIGHT) == RIGHT)
		data->x -= 100;
}

void	shift_colors(t_data *data, int keycode)
{
	(void)data;	
	(void)keycode;
	printf("colors");
}
void	zoom(t_data *data, int k)
{
	long long int x_t;

	if ((k & Z_OUT) == Z_OUT)	
	{
		data->sfsc.scld_x = data->sfsc.scld_x * 2.0;
		data->sfsc.scld_y = data->sfsc.scld_y * 2.0;
		data->x *= 0.5;
		data->y *= 0.5;
	}
	else if ((k & Z_IN) == Z_IN)	
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

void	get_controls (int keycode, t_data *data)
{
	printf("%i\n", keycode);
	if ((keycode & K << 8) == K << 8 && (keycode & COLORS << 16) == COLORS << 16)
		shift_colors(data, keycode);
	else if ((keycode & K << 8) == K << 8) 
		arrows_move(data, keycode);
	else if ((keycode & M << 8) == M << 8) 
		zoom(data, keycode);
}
