/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 03:15:09 by acrucesp          #+#    #+#             */
/*   Updated: 2021/07/16 22:57:48 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>
#include <stdio.h>
#include <unistd.h>

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

//add to libft
int	is_prime(int n)
{
	int	i;

	i = 1;
	while(++i < n)
		if (n % i == 0) 	
			return (0);
	return (1);
}

int n_escaled(int n)
{
	return ((255 * n) / M_ITER);
}

int	set_color(int n)
{
	if (n % 2 == 0)
		color = (n_escaled(n) << 16) | (127 << 8) | 127;	
	else
	{
		if(is_prime(ret))
			printf("%i is prime", ret);
	}
	return (color);
}

int	main(void)
{
	void		*mlx;
	void		*mlx_win;
	t_sfsc		sfsc;
	int x = 0;
	int y = 0;
	t_data	img;
	int color; 
	int ret;

	ft_memset(&sfsc, 0, sizeof(t_sfsc));
	get_sfsc(WIDTH, HEIGHT, &sfsc);
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, WIDTH, HEIGHT, "Wololo!!!");
	img.img = mlx_new_image(mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	while (x < WIDTH)
	{
		while(y < HEIGHT)
		{
			color = 0; 
			ret = mandel(x,y,&sfsc);
			if (ret > 1)
				color = set_color(ret);
			my_mlx_pixel_put(&img, x, y, color);
			y++;
		}
		y = 0;
		x++;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
