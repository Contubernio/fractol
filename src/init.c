/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albealva <albealva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 20:08:12 by albealva          #+#    #+#             */
/*   Updated: 2024/06/27 14:02:17 by albealva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_data(t_data *data)
{
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, "Fract'ol");
	data->img_ptr = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	data->img_data = mlx_get_data_addr(data->img_ptr, &data->bpp,
			&data->size_line, &data->endian);
	if (!data->mlx_ptr || !data->win_ptr || !data->img_ptr || !data->img_data)
	{
		write(2, "Error: Initialization failed.\n", 30);
		exit(1);
	}
	data->zoom = 1;
	data->move_x = 0.0;
	data->move_y = 0.0;
	data->c_re = -0.7;
	data->c_im = 0.27015;
	data->color_scheme = 0;
}

void	validate_julia_param(int param)
{
	const char	*error_message = "Error: Julia parm must be between 1 and 4.\n";

	if (param < 1 || param > 4)
	{
		write(2, error_message, ft_strlen(error_message));
		exit(1);
	}
}

void	adjust_julia_view(t_data *data)
{
	data->move_x = 0.0;
	data->move_y = 0.0;
	data->zoom = 1.1;
}

void	assign_julia_values(t_data *data, int param)
{
	if (param == 1)
	{
		data->c_re = -1.3;
		data->c_im = 0.00525;
	}
	else if (param == 2)
	{
		data->c_re = -0.72;
		data->c_im = -0.196;
	}
	else if (param == 3)
	{
		data->c_re = -0.1;
		data->c_im = 0.87;
	}
	else if (param == 4)
	{
		data->c_re = -0.51;
		data->c_im = -0.601;
	}
}

void	set_julia_params(t_data *data, int param)
{
	validate_julia_param(param);
	assign_julia_values(data, param);
	adjust_julia_view(data);
}
