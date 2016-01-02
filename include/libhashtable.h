/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/31 04:41:02 by jlagneau          #+#    #+#             */
/*   Updated: 2015/12/31 04:41:02 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASH_H
# define HASH_H
# ifdef LIBHASH_INTERNAL
#  include <libft.h>
typedef struct				s_hashtable_elem
{
	char					*key;
	void					*value;
}							t_hashtable_elem;
# endif

typedef						void(*t_hash_delete)(void *);

# ifdef LIBHASH_INTERNAL
struct						s_hashtable
{
   t_hash_delete			delete_func;
   t_list					*table;
};
#  define HASH_ELEM(elem)	(((t_list*)(elem))->content)
#  define HASH_KEY(elem)	((t_hashtable_elem*)HASH_ELEM((elem)))->key
#  define HASH_VALUE(elem)	((t_hashtable_elem*)HASH_ELEM((elem)))->value

t_hashtable_elem			*ht_find_elem(struct s_hashtable *ht, char *key);
# endif

typedef 					struct s_hashtable t_hashtable;

t_hashtable					*ht_create(t_hash_delete del);
void						ht_delete(t_hashtable **ht);
void						*ht_get(t_hashtable *ht, char *key);
int							ht_set(t_hashtable *ht, char *key, void *value);

#endif
