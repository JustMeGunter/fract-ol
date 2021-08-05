/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dpower.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 19:45:59 by acrucesp          #+#    #+#             */
/*   Updated: 2021/08/05 11:28:49 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_dpower(double base, double power)
{
	double	n_aux;

	if (!base)
		return (1);
	if (power < 0)
		return (0);
	n_aux = base;
	while (power-- > 1)
		base *= n_aux;
	return (base);
}
