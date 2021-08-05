/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 19:16:59 by acrucesp          #+#    #+#             */
/*   Updated: 2021/08/05 19:31:45 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static int	select_fractal_fnc(char **argv, t_data *data)
{
	if (argv[1] && !ft_strcmp(argv[1], "mandelbrot"))
		data->fractal = draw_mandelbrot;
	else if (argv[1] && !ft_strcmp(argv[1], "julia"))
		data->fractal = draw_julia;
	else if (argv[1] && !ft_strcmp(argv[1], "bonus_a"))
		data->fractal = draw_bonus_a;
	else if (argv[1] && !ft_strcmp(argv[1], "bonus_b"))
		data->fractal = draw_bonus_b;
	else
		return (1);
	return (0);
}

void	parse_args(int argc, char **argv, t_data *data)
{
	if (argc < 2 || select_fractal_fnc(argv, data))
	{
		printf("Enter one of the following sets:\nmandelbrot\njulia ");
		printf("\nbonus_a\nbonus_b");
		printf("\n**Julia can be followed by fractal parameters x y\n");
		printf("**Parameters cant be longer than 8 chars and must be 2.\n");
		exit(0);
	}
	if (argc > 2)
	{
		if (argv[2])
			if (ft_strlen(argv[2]) < 10)
				data->C.x = ft_atof(argv[2]);
		if (argv[3])
			if (ft_strlen(argv[3]) < 10)
				data->C.y = ft_atof(argv[3]);
	}
}
