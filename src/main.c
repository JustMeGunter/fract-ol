/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 03:15:09 by acrucesp          #+#    #+#             */
/*   Updated: 2021/07/21 22:04:11 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>
#include <stdio.h>
#include <unistd.h>

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->size_line+ x * (data->bits_per_pixel / 8));
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

unsigned int set_color(int red, int grn, int blue)
{
	return red + (grn << 8) + (blue << 16);
}

unsigned int rgb(double n)
{
	double ratio;
	int normalized;
	int x;
	unsigned int color;
	
	ratio = n / M_ITER;
	normalized = (int)(ratio * 256 * 3);
	x = normalized % 256;
	if ((int)n % 2 == 0)
		color = set_color(0, 255 - x, 255);	
	else
	{
		if(is_prime(n))
			color = set_color(x, 0, 255);	
		else
			color = set_color(255, 0, 255 - x);	
	}
	return (color);
}

int	key_hook(int keycode, t_data *data)
{
	(void)data;
	printf("key: %i\n", keycode);
	return (1);
}

int	fncTest(int x, int y)
{
	printf("%i x ,%i y\n", x, y);
	return (0);
}

int	main(void)
{
	t_sfsc		sfsc;
	int x = 0;
	int y = 0;
	t_data	data;
	unsigned int color; 
	double ret;
	ft_memset(&sfsc, 0, sizeof(t_sfsc));
	get_sfsc(WIDTH, HEIGHT, &sfsc);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "Wololo!!!");
	data.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.size_line, &data.endian);
	while (x < WIDTH)
	{
		while(y < HEIGHT)
		{
			color = 0; 
			ret = mandel(x,y,&sfsc);
			if (ret > 1)
				color = rgb(ret);
			my_mlx_pixel_put(&data, x, y, color);
			y++;
		}
		y = 0;
		x++;
	}
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
	mlx_mouse_hook(data.win, key_hook, &data);
	mlx_hook(data.win, 6, (1L<<6),fncTest, &data);
	mlx_loop(data.mlx);
}
