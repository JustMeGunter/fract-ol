/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_controls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 20:36:46 by acrucesp          #+#    #+#             */
/*   Updated: 2021/07/26 20:29:12 by acrucesp         ###   ########.fr       */
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
		if (k == 5)	
		{
			data->sfsc.scld_x = data->sfsc.scld_x * 2.0;
			data->sfsc.scld_y = data->sfsc.scld_y * 2.0;
			data->x *= 0.5;
			data->y *= 0.5;
		}
		else if (k == 4)	
		{
			data->sfsc.scld_x = data->sfsc.scld_x * 0.5;
			data->sfsc.scld_y = data->sfsc.scld_y * 0.5;
			data->x *= 2;
			data->y *= 2;
		}
}

void	get_controls (int k, t_data *data, char from)
{
	if (from == 'k')
		arrows_move(data, k);
	if (from == 'm')	
		zoom(data, k);
}
