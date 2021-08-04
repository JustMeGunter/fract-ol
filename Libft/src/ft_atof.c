/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 20:03:31 by acrucesp          #+#    #+#             */
/*   Updated: 2021/08/04 20:17:03 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

double	convert(char *str, int s)
{
	char	*aux_str;	
	int		i;
	double	d_p;
	double	ret;

	i = 0;
	d_p = 0;
	if (ft_strchr(str, '.'))
		d_p = ft_strlen(ft_strchr(str, '.')) - 1;
	aux_str = ft_calloc(ft_strlen(str), sizeof(char));
	if (!aux_str)
		return (0);
	while (*str)
	{
		if (*str != '.')
			aux_str[i++] = *str;
		str++;
	}
	ret = (double)ft_atoi(aux_str);
	if (d_p)
		ret = (double)ft_atoi(aux_str) / (double)ft_power(10, d_p);
	free(aux_str);
	if (s == -1)
		ret *= -1;
	return (ret);
}

double	ft_atof(char *str)
{
	int	i;
	int	dot;
	int	s;

	dot = 0;
	i = 0;
	s = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-')
		s = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (ft_isdigit(str[i]) || str[i] == '.')
	{
		if (str[i] == '.')
			dot++;
		if (dot > 1)
			return (0);
		i++;
	}
	if (i == (int)ft_strlen(str))
		return (convert(str, s));
	return (0);
}
