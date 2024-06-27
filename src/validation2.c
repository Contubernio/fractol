/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albealva <albealva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 21:27:25 by albealva          #+#    #+#             */
/*   Updated: 2024/06/27 15:16:21 by albealva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	validate_args(int argc, char **argv, t_data *data, int *julia_param)
{
	int	valid;

	valid = initial_validation(argc, argv, data);
	if (valid != 0)
	{
		return (valid);
	}
	return (final_validation(argc, argv, data, julia_param));
}

int	validate_params_2(int argc, t_data *data)
{
	(void)argc;
	(void)data;
	return (0);
}

int	initial_validation(int argc, char **argv, t_data *data)
{
	if (argc < 2 || argc > 3)
	{
		display_usage();
		return (1);
	}
	return (check_fractal_type(argc, argv, data));
}

int	final_validation(int argc, char **argv, t_data *data, int *julia_param)
{
	int	valid;

	valid = validate_params_2(argc, data);
	if (valid == 1)
	{
		return (1);
	}
	if (data->fractal_type == 2 && argc == 3)
	{
		if (argv[2] && argv[2][1] == '\0' && argv[2][0] >= '1'
			&& argv[2][0] <= '4')
		{
			*julia_param = argv[2][0] - '0';
		}
		else
		{
			write(2, "Error: Julia parameter must be between 1 and 4.\n", 47);
			return (1);
		}
	}
	return (2);
}
