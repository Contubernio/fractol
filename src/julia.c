/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albealva <albealva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 15:37:36 by albealva          #+#    #+#             */
/*   Updated: 2024/06/27 14:47:45 by albealva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	calculate_julia(t_fractal_params *params)
{
	double	new_re;
	double	new_im;
	double	old_re;
	double	old_im;
	int		i;

	new_re = params->param1;
	new_im = params->param2;
	old_re = 0;
	old_im = 0;
	i = 0;
	while (i < params->max_iter)
	{
		old_re = new_re;
		old_im = new_im;
		new_re = old_re * old_re - old_im * old_im + params->c1;
		new_im = 2 * old_re * old_im + params->c2;
		if ((new_re * new_re + new_im * new_im) > 4)
		{
			break ;
		}
		i++;
	}
	return (i);
}

void	draw_jul_col(t_data *data, int y, double scalex, double scaley)
{
	int					x;
	t_fractal_params	params;
	int					iteration;

	x = 0;
	while (x < WIDTH)
	{
		params.param1 = scalex * (x - WIDTH / 2)
			/ (0.5 * data->zoom * WIDTH) + data->move_x;
		params.param2 = scaley * (y - HEIGHT / 2)
			/ (0.5 * data->zoom * HEIGHT) + data->move_y;
		params.c1 = data->c_re;
		params.c2 = data->c_im;
		params.max_iter = 300;
		iteration = calculate_julia(&params);
		set_color(data, x, y, iteration);
		x++;
	}
}

void	draw_julia(t_data *data)
{
	const double	aspect_ratio = (double)WIDTH / HEIGHT;
	double			scalex;
	double			scaley;
	int				y;

	y = 0;
	if (aspect_ratio > 1)
	{
		scalex = 1.5 * aspect_ratio;
		scaley = 1.5;
	}
	else
	{
		scalex = 1.5;
		scaley = 1.5 / aspect_ratio;
	}
	while (y < HEIGHT)
	{
		draw_jul_col(data, y, scalex, scaley);
		y++;
	}
}
