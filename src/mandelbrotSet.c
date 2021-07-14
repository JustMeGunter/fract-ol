/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrotSet.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 19:30:40 by acrucesp          #+#    #+#             */
/*   Updated: 2021/07/14 21:53:18 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>


int mandel(double Px, double Py)
{
	double x0;
	double y0;
	double x;
	double x_t;
	double y;
	int i;
	int m_i;

	x = 0;
	y = 0;
	x_t = 0;
	i = 0;
	m_i = 1000;
	x0 = (Px - 990) * 0.0020833;
	y0 = (-Py + 600) * 0.003333;
	while (x*x + y*y <= 2*2 && i < m_i)
	{
		x_t = x*x - y*y + x0;
		y = 2*x*y + y0;
		x = x_t;
		i++;	
	}
	return (i);
}
