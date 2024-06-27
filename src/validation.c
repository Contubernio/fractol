/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albealva <albealva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 20:08:31 by albealva          #+#    #+#             */
/*   Updated: 2024/06/27 15:13:48 by albealva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	validate_params(t_data *data)
{
	const char	*error_message = "Err: Julia parm must be between -2 and 2.\n";

	if (data->fractal_type == 2)
	{
		if (data->c_re < -2 || data->c_re > 2
			|| data->c_im < -2 || data->c_im > 2)
		{
			write(2, error_message, ft_strlen(error_message));
			exit(1);
		}
	}
}

int	check_mandelbrot(int argc)
{
	if (argc != 2)
	{
		write(2, "Error: Mandelbrot only accepts 1 parameter.\n", 45);
		return (1);
	}
	return (0);
}

int	check_julia(int argc, char **argv)
{
	if (argc != 3 || argv[2] == NULL || argv[2][0] == '-')
	{
		write(2, "Error: Julia requires extra parm between 1 and 4.\n", 49);
		return (1);
	}
	if (argv[2][1] != '\0' || argv[2][0] < '1' || argv[2][0] > '4')
	{
		write(2, "Error: Julia parameter must be between 1 and 4.\n", 47);
		return (1);
	}
	return (0);
}

int	check_tricorn(int argc)
{
	if (argc != 2)
	{
		write(2, "Error: Tricorn only accepts 1 parameter.\n", 40);
		return (1);
	}
	return (0);
}

int	check_fractal_type(int argc, char **argv, t_data *data)
{
	data->fractal_type = argv[1][0] - '0';
	if (data->fractal_type < 1 || data->fractal_type > 3
		|| argv[1][1] != '\0')
	{
		display_usage();
		return (1);
	}
	if (data->fractal_type == 1)
	{
		return (check_mandelbrot(argc));
	}
	else if (data->fractal_type == 2)
	{
		return (check_julia(argc, argv));
	}
	else if (data->fractal_type == 3)
	{
		return (check_tricorn(argc));
	}
	return (0);
}
