/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 19:16:59 by acrucesp          #+#    #+#             */
/*   Updated: 2021/08/05 21:22:39 by acrucesp         ###   ########.fr       */
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

static int	iter_digit_parser(char *str)
{
	int	i;
	int	s;
	int	p;

	i = -1;
	s = 0;
	p = 0;
	while (str[++i])
	{
		if (str[i] == '-')
			s++;
		if (str[i] == '.')
			p++;
		if ((str[i] == '-' && s > 1) || (str[i] == '.' && p > 1))
			return (0);
		if (!ft_isdigit(str[i]) && str[i] != '.' && str[i] != '-')
			return (0);
	}
	if (i > 8)
		return (0);
	return (1);
}

static int	digit_parser(char *str1, char *str2)
{
	if (iter_digit_parser(str1) && iter_digit_parser(str2))
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
		if (digit_parser(argv[2], argv[3]))
		{
			if (argv[2])
				if (ft_strlen(argv[2]) < 10)
					data->C.x = ft_atof(argv[2]);
			if (argv[3])
				if (ft_strlen(argv[3]) < 10)
					data->C.y = ft_atof(argv[3]);
		}
	}
}
