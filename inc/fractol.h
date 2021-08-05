/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 03:05:43 by acrucesp          #+#    #+#             */
/*   Updated: 2021/08/05 23:06:43 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <mlx.h>
# include <libft.h>
# include <limits.h>
# define WIDTH 400 
# define HEIGHT 400 
# define M_ITER 100
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
# define I_C 6 
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

/* struct with data to operate with colors */
typedef struct s_color {
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	float			ratio;
	int				x;
	int				normalized;
}				t_color;

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
/* *colors is palette of colors												  */
/* c_s contais the color shift												  */
/* i_c cointains boolean for invert colors									  */
/* b_color contains base color												  */
/* zoom contains the zoom depth												  */
/* lock_zoom contains boolean for check the lock state					 	  */
/* sfsc has the shifted and scaled of the iamge 							  */
/* C complex number for fractal sets										  */
/******************************************************************************/
typedef struct s_data {
	void			*img;
	void			*win;
	void			*mlx;
	char			*addr;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
	int				m_iter;
	long long int	x;
	long long int	y;
	void			(*fractal)(struct s_data *data, int keycode);
	int				*colors;
	unsigned char	c_s;
	unsigned char	i_c;
	int				b_color;
	int				zoom;
	int				lock_zoom;
	t_sfsc			sfsc;
	t_ncomplex		C;
}				t_data;

void			draw_mandelbrot(t_data *data, int keycode);
void			draw_bonus_a(t_data *data, int keycode);
void			draw_bonus_b(t_data *data, int keycode);
void			get_sfsc(int x, int y, t_sfsc *sfsc);
void			draw_julia(t_data *data, int keycode);
void			get_controls(int k, t_data *data);
void			parse_args(int argc, char **argv, t_data *data);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
void			add_complex(t_ncomplex n1, t_ncomplex n2, t_ncomplex *ret);
void			pow_complex(t_ncomplex n1, t_ncomplex *ret);
void			get_colors(t_data *data);
void			load_data(t_data *data, int argc, char **argv);

#endif
