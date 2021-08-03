/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 03:05:43 by acrucesp          #+#    #+#             */
/*   Updated: 2021/08/03 11:44:32 by acrucesp         ###   ########.fr       */
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
# define M_ITER 100
/* .h file of defines */
# define COLORS 1
# define COLORS_MASK 65536
# define ITER 2
# define ITER_MASK 131072 
# define UP 126 
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define Z_IN 4
# define Z_OUT 5
# define C_IN 8
# define C_OUT 7
# define I_IN 24
# define I_OUT 27
# define ESC 53
# define K 107
# define K_MASK 27392
# define M 109
# define M_MASK 27904
# define MASK 0xFFFFFFFF 

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
	int		m_iter;
	long long int x;
	long long int y;
	void 	(*fractal)(struct s_data *data, int keycode);
	t_sfsc	sfsc;
	t_ncomplex C;
}				t_data;

int				mandelbrot(t_ncomplex *Z, t_ncomplex C, int i, int m_iter);
void			draw_mandelbrot(t_data *data, int keycode);
void			get_sfsc(int x, int y, t_sfsc *sfsc);
unsigned int 	rgb(double n);
void			draw_julia(t_data *data, int keycode);
void			get_controls(int k, t_data *data);
void			parse_args(int argc, char **argv, t_data *data);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
void			add_complex(t_ncomplex n1, t_ncomplex n2, t_ncomplex *ret);
void			pow_complex(t_ncomplex n1, t_ncomplex *ret);
void			reset_values(t_data *data, t_ncomplex *Z, int *color, int x, int y);

#endif
