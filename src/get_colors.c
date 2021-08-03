/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 19:23:35 by acrucesp          #+#    #+#             */
/*   Updated: 2021/08/03 13:39:15 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

unsigned int rgb(int m_iter, double value)
{
	float 	min;
	float 	max;
	float 	ratio;
	int		color;

	min = 0;
	max = (float)m_iter;
	ratio = 2.0 * (value - min) / (max - min);	
	color = (int)(fmax(0, 255 * (ratio - 1))) +
		(int)(255 - (fmax(0, 255 * (ratio - 1))) -
		(fmax(0, 255 * (ratio - 1)))) +
		(int)(fmax(0, 255 * (ratio - 1)));
	return (color);
}

void	get_colors(t_data *data)
{
	int i;

	i = 0;
	data->colors = malloc(sizeof(int) * data->m_iter);
	if (!data->colors)
		exit(0);
	while (i < data->m_iter)
	{
		data->colors[i] = rgb(data->m_iter, i);
		i++;
	}
}
