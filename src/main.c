/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 03:15:09 by acrucesp          #+#    #+#             */
/*   Updated: 2021/07/20 21:25:41 by acrucesp         ###   ########.fr       */
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

int	key_hook(int keycode, t_vars *vars)
{
	(void)vars;
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
	t_vars	vars;
	t_sfsc		sfsc;
	int x = 0;
	int y = 0;
	t_data	img;
	unsigned int color; 
	double ret;
	// vars and data in the same struct
	ft_memset(&sfsc, 0, sizeof(t_sfsc));
	get_sfsc(WIDTH, HEIGHT, &sfsc);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIDTH, HEIGHT, "Wololo!!!");
	img.img = mlx_new_image(vars.mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	while (x < WIDTH)
	{
		while(y < HEIGHT)
		{
			color = 0; 
			ret = mandel(x,y,&sfsc);
			if (ret > 1)
				color = rgb(ret);
			my_mlx_pixel_put(&img, x, y, color);
			y++;
		}
		y = 0;
		x++;
	}
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_mouse_hook(vars.win, key_hook, &vars);
	mlx_hook(vars.win, 6, (1L<<6),fncTest, &vars);
	mlx_loop(vars.mlx);
}
