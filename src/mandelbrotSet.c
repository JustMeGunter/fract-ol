/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrotSet.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 19:30:40 by acrucesp          #+#    #+#             */
/*   Updated: 2021/07/17 18:12:40 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int mandel(double Px, double Py, t_sfsc *sfsc)
{
	t_cplx cplx;

	ft_memset(&cplx, 0, sizeof(t_cplx));
	cplx.xC = (Px - sfsc->shftd_x) * sfsc->scld_x;
	cplx.yC = (-Py + sfsc->shftd_y) * sfsc->scld_y;
	while (cplx.x * cplx.x + cplx.y * cplx.y <= 4 && cplx.i < M_ITER)
	{
		cplx.t_x = cplx.x * cplx.x - cplx.y * cplx.y + cplx.xC;
		cplx.y = 2 * cplx.x * cplx.y + cplx.yC;
		cplx.x = cplx.t_x;
		cplx.i++;
	}
	return (cplx.i);
}
