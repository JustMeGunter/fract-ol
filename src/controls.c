/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 20:36:46 by acrucesp          #+#    #+#             */
/*   Updated: 2021/07/24 02:07:35 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	get_controls (int k, t_data *data)
{
	if (k == 126)
		data->y += 10;
	else if (k == 125)
		data->y -= 10;
	else if (k == 123)
		data->x -= 10;
	else if(k == 124)
		data->x += 10;
	printf("in x:%i, y:%i", data->x, data->y);
}
