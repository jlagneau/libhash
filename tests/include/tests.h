/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/02 04:59:03 by jlagneau          #+#    #+#             */
/*   Updated: 2016/01/02 04:59:03 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_H
# define TESTS_H
# include <libft.h>
# include <libhash.h>
# include <stdio.h>

# define TEST_ASSERT(m,t)	if(1){nb_asserts++;if(!(t))return m;}
# define TEST_ADD(t)		if(1){char *m=t();if(m)return m;}
# define TEST_RUN(t)		if(1){char *m=t();nb_tests++;if(m)return m;}

int							nb_tests;
int							nb_asserts;

char						*all_tests(void);
char						*static_string(void);
char						*malloc_string(void);

#endif
