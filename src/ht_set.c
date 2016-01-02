/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ht_set.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/31 05:06:31 by jlagneau          #+#    #+#             */
/*   Updated: 2015/12/31 05:06:31 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libhash.h>

/*
** Set a value for a key in the hashtable.
** If the value exist, it's replaced. Else a new entry is made in the hashtable.
**
** Possible returns :
** 1 if everything went good
** 0 if there was a problem
*/
int						ht_set(t_hashtable *ht, char *key, void *value)
{
	t_hashtable_elem	*e;
	t_list				*new_elem;

	e = NULL;
	new_elem = NULL;
	if ((e = ht_find_elem(ht, key)))
	{
		if (e->value)
			ht->delete_func(e->value);
		e->value = value;
	}
	else
	{
		if (!(e = ft_memalloc(sizeof(t_hashtable_elem))))
			return (0);
		if (!(e->key = ft_strdup(key)))
			return (0);
		e->value = value;
		if (!(new_elem = ft_lstnew(e, sizeof(*e))))
			return (0);
		ft_lstadd(&(ht->table), new_elem);
	}
	return (1);
}
