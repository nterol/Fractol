/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nterol <nterol@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 15:19:46 by nterol            #+#    #+#             */
/*   Updated: 2017/04/26 16:31:54 by nterol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void		error(void)
{
	ft_putendl("error");
	exit(0);
}

void		display(void)
{
	ft_putendl("Usage : ./fractol set_type");
	ft_putendl("Available sets :");
	ft_putendl("- julia ");
	ft_putendl("- mandelbrot");
	ft_putendl("- burningship");
	ft_putendl("Use arrow up & down or the scroll button to zoom in and out");
	ft_putendl("Use Left and Rigth arrow to switch between sets");
	ft_putendl("Use + and - to increase and decrease number of iterations");
	ft_putendl("- O : switch to sinus color gradient");
	ft_putendl("- P : switch to cosinus color gradient");
	ft_putendl("- O + P : switch to secondary palette");
	ft_putendl("On the Julia set use space bar to stop/restart the variations");
	exit(42);
}

void		check_set(int ac, char **av, t_ctol *uni)
{
	if (ac == 1)
		display();
	if (ac > 2)
		error();
	if (ft_strcmp(av[1], "julia") && ft_strcmp(av[1], "mandelbrot") &&\
			ft_strcmp(av[1], "burningship"))
		display();
	!ft_strcmp(av[1], "julia") ? uni->env.set = 0 : 0;
	!ft_strcmp(av[1], "mandelbrot") ? uni->env.set = 1 : 0;
	!ft_strcmp(av[1], "burningship") ? uni->env.set = 2 : 0;
}

int			main(int ac, char **av)
{
	t_ctol	*uni;

	uni = (t_ctol *)malloc(sizeof(t_ctol));
	if (!(uni))
		error();
	check_set(ac, av, uni);
	launcher(uni);
	return (0);
}
