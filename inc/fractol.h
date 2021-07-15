/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 03:05:43 by acrucesp          #+#    #+#             */
/*   Updated: 2021/07/15 22:35:32 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <stdlib.h>
# include <math.h>
# include <mlx.h>
# include <libft.h>
# define WIDTH 1920
# define HEIGHT 1200
# define M_ITER 1000

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_sfsc {
	float	shftd_x;
	float	shftd_y;
	float	scld_x;
	float	scld_y;	
}				t_sfsc;

typedef struct s_cplx {
	double	x;
	double	y;
	double	xC;
	double	yC;
	double	t_x;
	int		i;
}				t_cplx;

int		mandel(double Px, double Py, t_sfsc *sfsc);
void	get_sfsc(int x, int y, t_sfsc *sfsc);

#endif
