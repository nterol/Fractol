/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nterol <nterol@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 15:19:46 by nterol            #+#    #+#             */
/*   Updated: 2017/04/20 21:17:11 by nterol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		error(void)
{
	ft_putendl("error");
	exit(0);
}

void		display(void)
{
	ft_putendl("usage : ./fractol set_type");
	ft_putendl("available set");
	ft_putendl("- julia ");
	ft_putendl("- mandelbrot");
	ft_putendl("- burningship");
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
	!ft_strcmp(av[1], "julia") ? uni->env.set = 1 : 0;
	!ft_strcmp(av[1], "mandelbrot") ? uni->env.set = 2 : 0;
	!ft_strcmp(av[1], "burningship") ? uni->env.set = 3 : 0;
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
