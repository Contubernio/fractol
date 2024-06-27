/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albealva <albealva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 13:35:52 by albealva          #+#    #+#             */
/*   Updated: 2024/06/27 13:36:21 by albealva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	select_fractal(t_data *data)
{
	if (data->fractal_type == 1)
	{
		draw_mandelbrot(data);
	}
	else if (data->fractal_type == 2)
	{
		draw_julia(data);
	}
	else if (data->fractal_type == 3)
	{
		draw_tricorn(data);
	}
}
