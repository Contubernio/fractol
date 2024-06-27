/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albealva <albealva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 15:37:00 by albealva          #+#    #+#             */
/*   Updated: 2024/06/27 15:09:26 by albealva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	handle_info(int argc, char **argv)
{
	if (argc > 1 && ft_strcmp(argv[1], "info") == 0)
	{
		display_info();
		return (1);
	}
	return (0);
}

void	setup_and_run(t_data *data, int argc, int julia_param)
{
	init_data(data);
	if (data->fractal_type == 2 && argc == 3)
	{
		set_julia_params(data, julia_param);
	}
	validate_params(data);
	select_fractal(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
	hooks(data);
	mlx_loop(data->mlx_ptr);
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		julia_param;
	int		result;

	if (handle_info(argc, argv))
	{
		return (0);
	}
	result = validate_args(argc, argv, &data, &julia_param);
	if (result == 1)
	{
		return (1);
	}
	if (result == 0)
	{
		return (0);
	}
	setup_and_run(&data, argc, julia_param);
	return (0);
}
