/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ht_create.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/31 04:45:08 by jlagneau          #+#    #+#             */
/*   Updated: 2015/12/31 04:45:08 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libhash.h>

/*
** Create a hashtable.
** Require a function pointer `void (*del)(void*, t_size)`
**
** Possible returns :
** New hashtable pointer
** NULL if there was a problem
*/
t_hashtable			*ht_create(t_hash_delete del)
{
	t_hashtable		*hashtable;

	hashtable = NULL;
	if (!(hashtable = (t_hashtable*)ft_memalloc(sizeof(t_hashtable))))
		return (NULL);
	hashtable->table = NULL;
	if (!(hashtable->table = ft_lstnew(NULL, 0)))
	{
		ft_memdel((void**)&hashtable);
		return (NULL);
	}
	hashtable->delete_func = del;
	return (hashtable);
}
