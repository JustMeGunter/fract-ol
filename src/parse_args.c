/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 19:16:59 by acrucesp          #+#    #+#             */
/*   Updated: 2021/08/04 21:27:34 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int	select_fractal_fnc(char **argv, t_data *data)
{
	if (argv[1] && !ft_strncmp(argv[1], "mandelbrot", ft_strlen(argv[1])))
		data->fractal = draw_mandelbrot;
	else if (argv[1] && !ft_strncmp(argv[1], "julia", ft_strlen(argv[1])))
		data->fractal = draw_julia;
	else
		return (1);
	return(0);
}

void parse_args(int argc, char **argv, t_data *data)
{
	if (argc < 2 || select_fractal_fnc(argv, data))
	{
		printf("Enter one of the following sets:\nmandelbrot\njulia ");
		printf("\n**Julia can be followed by fractal parameters x y\n");
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
		if ((!data->C.y || !data->C.x) && !ft_strncmp(argv[1], "julia", ft_strlen(argv[1])))
		{
			printf("Parameters cant be longer than 10 digits and must be 2.");	
			exit(0);
		}
	}
}
