/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 15:26:15 by jlagneau          #+#    #+#             */
/*   Updated: 2015/11/30 15:26:31 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int			main(void)
{
	char	*result;

	result = all_tests();
	if (result != NULL)
	{
		ft_putstr("\033[31mFAILED: \033[0m");
		ft_putendl(result);
	}
	else
		ft_putendl("\033[32mALL TESTS PASSED\033[0m");
	ft_putstr("Tests run: ");
	ft_putnbr(nb_tests);
	ft_putstr(", assertions: ");
	ft_putnbr(nb_asserts);
	ft_putchar('\n');
	return (result != NULL);
}
