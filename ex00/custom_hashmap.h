/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_hashmap.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshabali <sshabali@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 09:26:20 by sshabali          #+#    #+#             */
/*   Updated: 2024/09/15 09:26:24 by sshabali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define HASHMAP_SIZE		300
#define MAX_VALUE_LENGTH	3000
#define MAX_LINE_LENGTH		3000

typedef struct t_item
{
	long long		key;
	char			val[MAX_VALUE_LENGTH];
}	t_item;

typedef struct t_hashmap
{
	t_item	*table[HASHMAP_SIZE];
}	t_hashmap;
