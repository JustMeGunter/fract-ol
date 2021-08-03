/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 19:16:59 by acrucesp          #+#    #+#             */
/*   Updated: 2021/08/03 21:36:45 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int	select_fractal_fnc(char **argv, t_data *data)
{
	if (argv[1] && !ft_strncmp(argv[1], "mandelbrot", ft_strlen(argv[1])))
		data->fractal = draw_mandelbrot;
	else if (argv[2] && !ft_strncmp(argv[2], "julia", ft_strlen(argv[2])))
		data->fractal = draw_julia;
	else
		return (1);
	return(0);
}

//float	atof(char *str)
//{
//	float ret;
//
//	ret = atoi(str);
//	if (ft_strchr(str, '.'))
//		
//	
//}

void parse_args(int argc, char **argv, t_data *data)
{
	if (argc < 2 || select_fractal_fnc(argv, data))
	{
		printf("Enter one of the following sets:\nmandelbrot\njulia ");
		printf("\n**Can be followed by fractal parameters x y\n");
		exit(0);
	}
	else if (argc > 2)
	{
		data->C.x = ft_atoi(argv[2]);
		data->C.y = ft_atoi(argv[3]);
	}
}
