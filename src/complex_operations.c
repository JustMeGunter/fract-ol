/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 19:32:30 by acrucesp          #+#    #+#             */
/*   Updated: 2021/07/28 22:19:57 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	pow_complex(t_ncomplex n1, t_ncomplex *res)
{
	res->x = (ft_dpower(n1.x, 2) + (-1 * ft_dpower(n1.y, 2)));
	res->y = (2 * n1.x * n1.y);
}

void	add_complex(t_ncomplex n1, t_ncomplex n2, t_ncomplex *res)
{
	res->x = n1.x + n2.x;
	res->y = n1.y + n2.y;
}

