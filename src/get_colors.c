/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 19:23:35 by acrucesp          #+#    #+#             */
/*   Updated: 2021/08/05 10:30:45 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static void	pairs(t_data *data, t_color *clr, int m_iter)
{
	clr->b = fmax(0, (m_iter - clr->x) * (1 - clr->ratio));
	clr->r = fmax(0, (m_iter - data->c_s) * (clr->ratio - 1));
	clr->g = (254 + data->c_s - clr->b - clr->r);
}

static void	odds(t_data *data, t_color *clr, int m_iter)
{
	clr->b = fmax(0, (m_iter - data->c_s) * (1 - clr->ratio));
	clr->r = fmax(0, (m_iter - clr->x) * (clr->ratio - 1));
	clr->g = (255 + data->c_s - clr->b - clr->r);
}

static void	primes(t_data *data, t_color *clr, int m_iter)
{
	clr->b = fmax(0, (m_iter - data->c_s) * (1 - clr->ratio));
	clr->r = fmax(0, (m_iter - data->c_s) * (clr->ratio - 1));
	clr->g = 255 - clr->b - clr->r + clr->x;
}

static int	rgb(int m_iter, double value, t_data *data)
{
	t_color	clr;

	clr.ratio = 2 * (value - 0) / (m_iter - 0);
	clr.normalized = (int)(clr.ratio * 256 * 3);
	clr.x = clr.normalized % 256;
	if ((int)value % 2 == 0)
		pairs(data, &clr, m_iter);
	else
	{
		if (ft_is_prime(value))
			odds(data, &clr, m_iter);
		else
			primes(data, &clr, m_iter);
	}
	return (clr.r + (clr.g << 8) + (clr.b << 16));
}

void	get_colors(t_data *data)
{
	int	i;

	i = 0;
	data->colors = malloc(sizeof(int) * data->m_iter);
	if (!data->colors)
		exit(0);
	while (i < data->m_iter)
	{
		data->colors[i] = rgb(data->m_iter, i, data);
		i++;
	}
}
