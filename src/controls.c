/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 20:36:46 by acrucesp          #+#    #+#             */
/*   Updated: 2021/07/24 21:49:27 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	get_controls (int k, t_data *data, char from)
{
	if (from == 'k')
	{
		if (k == 126)
			data->y -= 10;
		else if (k == 125)
			data->y += 10;
		else if (k == 123)
			data->x -= 10;
		else if(k == 124)
			data->x += 10;
	}
	else
	{
		if (k == 5)	
		{
			data->x_z += 0.001;
			data->y_z += 0.001;
		}
		else if (k == 4)	
		{
			data->x_z -= 0.001;
			data->y_z -= 0.001;
		}
		printf("pass");
	}
	printf("in x:%i, y:%i", data->x, data->y);
}
