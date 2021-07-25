/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 20:36:46 by acrucesp          #+#    #+#             */
/*   Updated: 2021/07/25 21:37:17 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	get_controls (int k, t_data *data, char from)
{
	if (from == 'k')
	{
		if (k == 125)
			data->y -= 100;
		else if (k == 126)
			data->y += 100;
		else if (k == 123)
			data->x -= 100;
		else if(k == 124)
			data->x += 100;
	}
	if (from == 'm')	
	{
		if (k == 5)	
		{
			data->sfsc.scld_x += data->sfsc.scld_x * 2.0;
			data->sfsc.scld_y += data->sfsc.scld_y * 2.0;
			data->x *= 0.5;
			data->y *= 0.5;
		}
		else if (k == 4)	
		{
			data->sfsc.scld_x -= data->sfsc.scld_x * 0.5;
			data->sfsc.scld_y -= data->sfsc.scld_y * 0.5;
			data->x *= 2;
			data->y *= 2;
		//	data->x += 280;
		//	data->y -= 0;
		}
		printf("pass\n");
	}
	printf("in x:%lli, y:%lli \ndata: %lf %lf\n", data->x, data->y, data->sfsc.scld_x,data->sfsc.scld_y);
}
