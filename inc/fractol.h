/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 03:05:43 by acrucesp          #+#    #+#             */
/*   Updated: 2021/07/31 19:45:02 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <mlx.h>
# include <libft.h>
# define WIDTH 400 
# define HEIGHT 400 
# define M_ITER 1000
/* Arrows directions */
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
/* Escape key */
# define ESC 53

/*struct to operate shifted and scaled an axis */
typedef struct s_sfsc {
	long double	shftd_x;
	long double	shftd_y;
	long double	scld_x;
	long double	scld_y;	
}				t_sfsc;

/* struc complex number */
typedef struct s_ncomplex {
	long double	x;
	long double	y;
}				t_ncomplex;

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
/* x contains coord to use in controls										  */
/* y contains coord to use in controls										  */
/* (* fractal) the function of the fractal type								  */
/* sfsc has the shifted and scaled of the iamge 							  */
/* C complex number for fractal sets										  */
/******************************************************************************/
typedef struct	s_data {
	void	*img;
	void	*win;
	void	*mlx;
	char	*addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	long long int x;
	long long int y;
	void 	(*fractal)(struct s_data *data, char k, char t);
	t_sfsc	sfsc;
	t_ncomplex C;
}				t_data;

int				mandelbrot(t_ncomplex *Z, t_ncomplex C, int i);
void			draw_mandelbrot(t_data *data, char keycode, char t);
void			get_sfsc(int x, int y, t_sfsc *sfsc);
unsigned int 	rgb(double n);
void			draw_julia(t_data *data, char keycode, char t);
void			get_controls(int k, t_data *data, char from);
void			parse_args(int argc, char **argv, t_data *data);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
void			add_complex(t_ncomplex n1, t_ncomplex n2, t_ncomplex *ret);
void			pow_complex(t_ncomplex n1, t_ncomplex *ret);

#endif
