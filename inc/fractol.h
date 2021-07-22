/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 03:05:43 by acrucesp          #+#    #+#             */
/*   Updated: 2021/07/22 20:28:01 by acrucesp         ###   ########.fr       */
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

/******************************************************************************/
/* s_data is the struct that has data form manipulate the window and the image*/
/* img contains an identifier of the image									  */
/* win contains an identifier of the window									  */
/* mlx contais an idenfier of the X-Window network service					  */
/* addr cointais an adress of the image where is stored						  */
/* bits_per_pixel contains a int filled with the numbers of bits necesarys to */
/*	represent a color														  */
/* size_line contains the number bytes used to store one line of the image in */
/*	memmory																	  */
/* endian contains a number that tells the format of byte					  */
/******************************************************************************/
typedef struct	s_data {
	void	*img;
	void	*win;
	void	*mlx;
	char	*addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}				t_data;

/*struct to operate shifted and scaled an axis */
typedef struct s_sfsc {
	float	shftd_x;
	float	shftd_y;
	float	scld_x;
	float	scld_y;	
}				t_sfsc;

/*struct to operate with two complex numbers*/
typedef struct s_cplx {
	double	x;
	double	y;
	double	xC;
	double	yC;
	double	t_x;
	int		i;
}				t_cplx;

int				mandel(double Px, double Py, t_sfsc *sfsc);
void			get_sfsc(int x, int y, t_sfsc *sfsc);
unsigned int 	rgb(double n);
void			draw_mandel(t_sfsc *sfsc, t_data *data);

#endif
