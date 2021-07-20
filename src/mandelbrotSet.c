/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrotSet.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 19:30:40 by acrucesp          #+#    #+#             */
/*   Updated: 2021/07/20 21:48:57 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int mandel(double Px, double Py, t_sfsc *sfsc)
{
	t_cplx cplx;

	//generar dos acumuladores para x e y /2 
	ft_memset(&cplx, 0, sizeof(t_cplx));
	cplx.xC = (Px + 300 + 150  + 200- sfsc->shftd_x) * sfsc->scld_x;
	cplx.yC = (-Py + 400 - 500 + sfsc->shftd_y) * sfsc->scld_y;
	while (cplx.x * cplx.x + cplx.y * cplx.y <= 4 && cplx.i < M_ITER)
	{
		cplx.t_x = cplx.x * cplx.x - cplx.y * cplx.y + cplx.xC;
		cplx.y = 2 * cplx.x * cplx.y + cplx.yC;
		cplx.x = cplx.t_x;
		cplx.i++;
	}
	return (cplx.i);
}
