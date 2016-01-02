/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   static_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/02 07:10:38 by jlagneau          #+#    #+#             */
/*   Updated: 2016/01/02 07:10:38 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static void			static_string_delete(void *e)
{
	(void)e;
}

char				*static_string_hash_reassign(void)
{
	t_hashtable		*h;

	h = ht_create(&static_string_delete);
	TEST_ASSERT(
		"Hash key1 assign in __FUNCTION__",
		ht_set(h, "key1", "value1")
	);
	TEST_ASSERT(
		"Hash key1 compare in __FUNCTION__",
		ft_strcmp(ht_get(h, "key1"),"value1") == 0
	);
	TEST_ASSERT(
		"Hash key1 reassign in __FUNCTION__",
		ht_set(h, "key1", "value2")
	);
	TEST_ASSERT(
		"Hash key1 compare old value in __FUNCTION__",
		ft_strcmp(ht_get(h, "key1"), "value1") != 0
	);
	TEST_ASSERT(
		"Hash key1 compare new value in __FUNCTION__",
		ft_strcmp(ht_get(h, "key1"), "value2") == 0
	);
	ht_delete(&h);
	return (NULL);
}

char				*static_string_hash_assign(void)
{
	t_hashtable		*h;

	h = ht_create(&static_string_delete);
	TEST_ASSERT(
		"Hash key1 assign in __FUNCTION__",
		ht_set(h, "key1", "value1")
	);
	TEST_ASSERT(
		"Hash key1 assign in __FUNCTION__",
		ht_set(h, "key2", "value2")
	);
	TEST_ASSERT(
		"Hash key1 compare in __FUNCTION__",
		ft_strcmp(ht_get(h, "key1"), "value1") == 0
	);
	TEST_ASSERT(
		"Hash key2 compare in __FUNCTION__",
		ft_strcmp(ht_get(h, "key2"), "value2") == 0
	);
	TEST_ASSERT(
		"Hash key non assigned in __FUNCTION__",
		ht_get(h, "key3") == NULL
	);
	ht_delete(&h);
	return (NULL);
}

char				*static_string(void)
{
	TEST_RUN(static_string_hash_assign);
	TEST_RUN(static_string_hash_reassign);
	return (NULL);
}
