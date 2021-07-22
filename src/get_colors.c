/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 19:23:35 by acrucesp          #+#    #+#             */
/*   Updated: 2021/07/22 19:36:19 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

unsigned int set_color(int red, int grn, int blue)
{
	return red + (grn << 8) + (blue << 16);
}

unsigned int rgb(double n)
{
	double ratio;
	int normalized;
	int x;
	unsigned int color;
	
	ratio = n / M_ITER;
	normalized = (int)(ratio * 256 * 3);
	x = normalized % 256;
	if ((int)n % 2 == 0)
		color = set_color(0, 255 - x, 255);	
	else
	{
		if(ft_is_prime(n))
			color = set_color(x, 0, 255);	
		else
			color = set_color(255, 0, 255 - x);	
	}
	return (color);
}
