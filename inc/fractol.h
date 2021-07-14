/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 03:05:43 by acrucesp          #+#    #+#             */
/*   Updated: 2021/07/14 22:35:22 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <stdlib.h>
# include <math.h>
# include <mlx.h>
# define WIDTH 1920
# define HEIGHT 1200

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_params {
	int		shftd_x;
	int		shftd_y;
	float	scld_x;
	float	scld_y;	
}				t_params;

int	mandel(double Px, double Py);

#endif
