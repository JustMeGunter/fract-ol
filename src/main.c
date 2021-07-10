/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 03:15:09 by acrucesp          #+#    #+#             */
/*   Updated: 2021/07/10 21:32:33 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

typedef	struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void test_mandel(double Px, double Py, t_data img)
{
	int color = 0x00FF0000; 
	double x0 = (Px/480)-2;
	double y0 = (Py/270)-2;
	double x = 0;
	double x_t = 0;
	double y  = 0;
	int i = 0;
	int m_i = 100;
	while (x*x + y*y <= 2*2 && i < m_i)
	{
		x_t = x*x - y*y + x0;
		y = 2*x*y + y0;
		x = x_t;
		i++;	
	}
	if (i > 50)
		color = 0x00000000;
	my_mlx_pixel_put(&img, Px, Py, color);
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	int x = 0;
	int y = 0;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Wololo!!!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	while (x < 1920)
	{
		while(y < 1080)
		{
			test_mandel(x,y,img);
			y++;
		}
		y = 0;
		x++;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
