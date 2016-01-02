/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 16:53:06 by jlagneau          #+#    #+#             */
/*   Updated: 2016/01/01 16:53:06 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

char			*all_tests(void)
{
	TEST_ADD(static_string);
	TEST_ADD(malloc_string);
	return (NULL);
}
