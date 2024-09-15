/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_hashmap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshabali <sshabali@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 09:25:28 by sshabali          #+#    #+#             */
/*   Updated: 2024/09/15 09:25:33 by sshabali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "custom_hashmap.h"
#include <stdlib.h>

int	str_len(char *s);

/*
1/ this function initializes the hashmap using malloc().
2/ anitialize the table array of the hash map, setting 
each element to NULL to mark them as empty.
3/ the function returns the newly created and initialized 
hashmap.
*/
t_hashmap	*create_table(void)
{
	t_hashmap	*hashmap;
	int			i;

	hashmap = malloc(sizeof(t_hashmap));
	i = 0;
	while (i < HASHMAP_SIZE)
	{
		hashmap->table[i] = NULL;
		i++;
	}
	return (hashmap);
}

/*
Function allocates memory for a new t_item 
structure to hold the key-value pair. and sets the "key" 
field of the new item.
2/ copies the value string into the value field of the new 
item ensuring not to exceed MAX_VALUE_LENGTH -1 characters.
The string is then NULL terminated.
3/in the while loop we search for an empty slot (NULL) in 
the hash map's table array. If the table is full the function 
exists and if not a new item is inserted into the first 
available slot. 
*/
void	insert(t_hashmap *hashmap, long long key, char *val)
{
	int		i;
	t_item	*new_item;

	new_item = malloc(sizeof(t_item));
	new_item->key = key;
	i = 0;
	while (*val && i < MAX_VALUE_LENGTH - 1)
	{
		new_item->val[i] = *val;
		val++;
		i++;
	}
	new_item->val[i] = '\0';
	i = 0;
	while (hashmap->table[i] != NULL && i < HASHMAP_SIZE)
		i++;
	if (i >= HASHMAP_SIZE)
		return ;
	hashmap->table[i] = new_item;
}

void	insert_2(t_hashmap *hashmap, char *key, char *val)
{
	int		i;
	t_item	*new_item;

	new_item = malloc(sizeof(t_item));
	if (str_len(key) < 3)
		return ;
	if (str_len(key) == 3)
		new_item->key = 0;
	else
		new_item->key = (str_len(key)) / 3;
	i = 0;
	while (*val && i < MAX_VALUE_LENGTH - 1)
	{
		new_item->val[i] = *val;
		val++;
		i++;
	}
	new_item->val[i] = '\0';
	i = 0;
	while (hashmap->table[i] != NULL && i < HASHMAP_SIZE)
		i++;
	if (i >= HASHMAP_SIZE)
		return ;
	hashmap->table[i] = new_item;
}

/* 
this function searches for a value based on the key in the
hash map. Loops through the hash map's table, if a matching 
key is found returns the associated value. if no match is
found and the end of the table is reached it returns (Null).
*/
char	*search(t_hashmap *hashmap, long long key)
{
	int	i;

	i = 0;
	while (hashmap->table[i] != NULL)
	{
		if (hashmap->table[i]->key == key)
		{
			return (hashmap->table[i]->val);
		}
		i++;
	}
	return (NULL);
}

/*frees the memory allocated for the hash map. frees each item
that is not (NULL) and frees the memory allocated for the 
hash map itself*/
void	free_hashmap(t_hashmap *hashmap)
{
	t_item	*item;
	int		i;

	i = 0;
	while (i < HASHMAP_SIZE)
	{
		item = hashmap->table[i];
		if (item == NULL)
		{
			break ;
		}
		free(item);
		i++;
	}
	free(hashmap);
}
