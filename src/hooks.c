/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albealva <albealva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 15:38:15 by albealva          #+#    #+#             */
/*   Updated: 2024/06/27 14:00:59 by albealva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	color_scheme(int keycode, t_data *data)
{
	if (keycode == XK_KP_Divide)
	{
		data->color_scheme = (data->color_scheme + 1) % COLOR_SCHEMES;
	}
	else if (keycode == XK_KP_Multiply)
	{
		data->color_scheme = (data->color_scheme - 1
				+ COLOR_SCHEMES) % COLOR_SCHEMES;
	}
}

void	zoom_handle(int button, t_data *data, t_mouse_params *params)
{
	const double	zoom_in = 1.5;
	const double	zoom_out = 1.0 / zoom_in;

	if (button == 4)
	{
		data->zoom *= zoom_out;
	}
	else if (button == 5)
	{
		data->zoom *= zoom_in;
	}
	params->zoom = data->zoom;
}

void	move_handle(int keycode, t_data *data)
{
	if (keycode == XK_Up)
	{
		data->move_y -= 0.1 / data->zoom;
	}
	else if (keycode == XK_Down)
	{
		data->move_y += 0.1 / data->zoom;
	}
	else if (keycode == XK_Left)
	{
		data->move_x -= 0.1 / data->zoom;
	}
	else if (keycode == XK_Right)
	{
		data->move_x += 0.1 / data->zoom;
	}
}
