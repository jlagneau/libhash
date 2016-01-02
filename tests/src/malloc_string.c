/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/02 07:10:30 by jlagneau          #+#    #+#             */
/*   Updated: 2016/01/02 07:10:30 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

static void			malloc_string_delete(void *e)
{
	ft_strdel((char**)&e);
}

char				*malloc_string_hash_reassign(void)
{
	t_hashtable		*h;

	h = ht_create(&malloc_string_delete);
	TEST_ASSERT(
		"Hash key1 assign value in "__FILE__,
		ht_set(h, "key1", ft_strdup("value1"))
	);
	TEST_ASSERT(
		"Hash key1 compare value in "__FILE__,
		ft_strcmp(ht_get(h, "key1"),"value1") == 0
	);
	TEST_ASSERT(
		"Hash key1 reassign value in "__FILE__,
		ht_set(h, "key1", ft_strdup("value2"))
	);
	TEST_ASSERT(
		"Hash key compare with old value in "__FILE__,
		ft_strcmp(ht_get(h, "key1"), "value1") != 0
	);
	TEST_ASSERT(
		"Hash key compare with new value in "__FILE__,
		ft_strcmp(ht_get(h, "key1"), "value2") == 0
	);
	ht_delete(&h);
	return (NULL);
}

char				*malloc_string_hash_assign(void)
{
	t_hashtable		*h;

	h = ht_create(&malloc_string_delete);
	TEST_ASSERT(
		"Hash key1 assign value in "__FILE__,
		ht_set(h, "key1", ft_strdup("value1"))
	);
	TEST_ASSERT(
		"Hash key2 assign value in "__FILE__,
		ht_set(h, "key2", ft_strdup("value2"))
	);
	TEST_ASSERT(
		"Hash key1 compare value in "__FILE__,
		ft_strcmp(ht_get(h, "key1"), "value1") == 0
	);
	TEST_ASSERT(
		"Hash key2 compare value in "__FILE__,
		ft_strcmp(ht_get(h, "key2"), "value2") == 0
	);
	TEST_ASSERT(
		"Hash key non assigned in "__FILE__,
		ht_get(h, "key3") == NULL
	);
	ht_delete(&h);
	return (NULL);
}

char				*malloc_string(void)
{
	TEST_RUN(malloc_string_hash_assign);
	TEST_RUN(malloc_string_hash_reassign);
	return (NULL);
}
