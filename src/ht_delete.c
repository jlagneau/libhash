/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ht_delete.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/31 06:14:00 by jlagneau          #+#    #+#             */
/*   Updated: 2015/12/31 06:14:00 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libhash.h>

static t_hash_delete		set_func(t_hash_delete del)
{
	static t_hash_delete	f = NULL;

	if (del)
		f = del;
	return (f);
}

static void					delete_table(void *e, t_size size)
{
	t_hash_delete			f;
	t_hashtable_elem		*el;

	f = set_func(NULL);
	el = e;
	if (size)
	{
		ft_strdel(&(el->key));
		f(el->value);
		ft_memdel(&e);
	}
}

/*
** Delete hashtable.
*/
void						ht_delete(t_hashtable **ht)
{
	set_func((*ht)->delete_func);
	ft_lstdel(&((*ht)->table), &delete_table);
	(*ht)->delete_func = NULL;
	ft_memdel((void**)&(*ht));
	*ht = NULL;
}
