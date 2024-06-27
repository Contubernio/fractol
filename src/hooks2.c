/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albealva <albealva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 13:31:27 by albealva          #+#    #+#             */
/*   Updated: 2024/06/27 13:57:14 by albealva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	calc_mouse(t_mouse_params *params, double *mouse_x, double *mouse_y)
{
	*mouse_x = (params->win_x - WIDTH / 2)
		/ (0.5 * params->zoom * WIDTH) + params->move_x;
	*mouse_y = (params->win_y - HEIGHT / 2)
		/ (0.5 * params->zoom * HEIGHT) + params->move_y;
}

int	mouse_scroll(int button, int x, int y, t_data *data)
{
	double			old_mouse_x;
	double			old_mouse_y;
	double			new_mouse_x;
	double			new_mouse_y;
	t_mouse_params	params;

	params.zoom = data->zoom;
	params.move_x = data->move_x;
	params.move_y = data->move_y;
	params.win_x = x;
	params.win_y = y;
	calc_mouse(&params, &old_mouse_x, &old_mouse_y);
	zoom_handle(button, data, &params);
	calc_mouse(&params, &new_mouse_x, &new_mouse_y);
	data->move_x += old_mouse_x - new_mouse_x;
	data->move_y += old_mouse_y - new_mouse_y;
	select_fractal(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
	return (0);
}

int	key_press(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		exit(0);
	}
	move_handle(keycode, data);
	color_scheme(keycode, data);
	select_fractal(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
	return (0);
}

void	hooks(t_data *data)
{
	mlx_key_hook(data->win_ptr, key_press, data);
	mlx_mouse_hook(data->win_ptr, mouse_scroll, data);
}
