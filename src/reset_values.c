/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_values.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 17:02:26 by acrucesp          #+#    #+#             */
/*   Updated: 2021/08/01 17:02:50 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void reset_values(t_data *data, t_ncomplex *Z, int *color, int x, int y)
{
	*color = 0x00000000; 
	data->C.x = (x - data->x - data->sfsc.shftd_x) * data->sfsc.scld_x;
	data->C.y = (-y + data->y + data->sfsc.shftd_y) * data->sfsc.scld_y;
	ft_memset(Z, 0, sizeof(t_ncomplex));
}
