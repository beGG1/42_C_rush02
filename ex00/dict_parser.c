/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshabali <sshabali@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 07:35:25 by sshabali          #+#    #+#             */
/*   Updated: 2024/09/15 07:35:31 by sshabali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "custom_hashmap.h"
#include <stdio.h>

void		insert(t_hashmap *hashmap, long long key, char *val);
void		insert_2(t_hashmap *hashmap, char *key, char *val);
int			str_len(char *s);
long long	str_num(char *str);

void	parse_string(char *str, char *key, char *val)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] != ' ' && str[i] != ':')
	{
		key[j] = str[i];
		j++;
		i++;
	}
	key[j] = '\0';
	while (str[i] != ':')
		i++;
	i++;
	while (str[i] == ' ')
		i++;
	j = 0;
	while (str[i] != '\0')
	{
		val[j] = str[i];
		j++;
		i++;
	}
	val[j] = '\0';
}

void	parse_dict(char *dict, int size, t_hashmap *single, t_hashmap *hashmap)
{
	int		i;
	int		j;
	char	str[MAX_LINE_LENGTH];
	char	key[MAX_LINE_LENGTH];
	char	val[MAX_LINE_LENGTH];

	i = 0;
	while (i < size)
	{
		j = 0;
		while (dict[i] != '\n')
		{
			str[j] = dict[i];
			j++;
			i++;
		}
		str[j] = '\0';
		parse_string(str, key, val);
		if (str_len(key) <= 2)
			insert(single, str_num(key), val);
		else
			insert_2(hashmap, key, val);
		i++;
	}
}
