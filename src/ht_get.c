/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ht_get.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau </var/spool/mail/jlagneau>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/31 08:21:29 by jlagneau          #+#    #+#             */
/*   Updated: 2015/12/31 08:21:29 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libhash.h>

/*
** Get value from hashtable for a given key.
**
** Possible returns:
** Value address if key exist
** NULL if key does not exist
*/
void					*ht_get(t_hashtable *ht, char *key)
{
	t_hashtable_elem	*e;

	e = NULL;
	if ((e = ht_find_elem(ht, key)))
		return (e->value);
	return (NULL);
}
