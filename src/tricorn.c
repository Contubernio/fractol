/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tricorn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albealva <albealva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 15:37:22 by albealva          #+#    #+#             */
/*   Updated: 2024/06/27 12:29:20 by albealva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	calculate_tricorn(t_fractal_params *params)
{
	double	new_re;
	double	new_im;
	double	old_re;
	double	old_im;
	int		i;

	new_re = 0;
	new_im = 0;
	old_re = 0;
	old_im = 0;
	i = 0;
	while (i < params->max_iter)
	{
		old_re = new_re;
		old_im = new_im;
		new_re = old_re * old_re - old_im * old_im + params->param1;
		new_im = -2 * old_re * old_im + params->param2;
		if ((new_re * new_re + new_im * new_im) > 4)
		{
			break ;
		}
		i++;
	}
	return (i);
}

void	draw_tri_column(t_data *data, int x, double x_scale, double y_scale)
{
	int					y;
	t_fractal_params	params;
	int					iteration;

	y = 0;
	while (y < HEIGHT)
	{
		params.param1 = x_scale * (x - WIDTH / 2)
			/ (0.5 * data->zoom * WIDTH) + data->move_x;
		params.param2 = y_scale * (y - HEIGHT / 2)
			/ (0.5 * data->zoom * HEIGHT) + data->move_y;
		params.max_iter = 300;
		iteration = calculate_tricorn(&params);
		set_color(data, x, y, iteration);
		y++;
	}
}

void	draw_tricorn(t_data *data)
{
	const double	x_scale = 1.5;
	const double	y_scale = 1.2;
	int				x;

	x = 0;
	while (x < WIDTH)
	{
		draw_tri_column(data, x, x_scale, y_scale);
		x++;
	}
}
