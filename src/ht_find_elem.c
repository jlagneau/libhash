/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_elem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/31 05:26:31 by jlagneau          #+#    #+#             */
/*   Updated: 2015/12/31 05:26:31 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libhash.h>

t_hashtable_elem	*ht_find_elem(t_hashtable *ht, char *key)
{
	t_list			*tmp;

	tmp = ht->table;
	if (HASH_ELEM(tmp) == NULL)
	{
		if (!(tmp->content = ft_memalloc(sizeof(t_hashtable_elem))))
			return (NULL);
		HASH_KEY(tmp) = ft_strdup(key);
		HASH_VALUE(tmp) = NULL;
		return (HASH_ELEM(tmp));
	}
	while (tmp)
	{
		if (ft_strcmp(HASH_KEY(tmp), key) == 0)
			return (HASH_ELEM(tmp));
		tmp = tmp->next;
	}
	return (NULL);
}
