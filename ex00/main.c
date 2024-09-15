/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshabali <sshabali@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 11:45:33 by sshabali          #+#    #+#             */
/*   Updated: 2024/09/14 11:58:01 by sshabali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h> 
#include <unistd.h>
#include <fcntl.h>
#include "custom_hashmap.h"

int			print_string(char *msg);
long long	str_num(char *str);
char		*slice(char *s, int from, int to);
int			print_string_space(char *msg, int flag);
void		parse_dict(char *dict, int size,
				t_hashmap *single, t_hashmap *hashmap);
int			get_file_size(char *path);
char		*read_full_file(char *path, int size, char *buffer);
t_hashmap	*create_table(void);
void		insert(t_hashmap *hashmap, long long key, char *val);
int			str_len(char *s);
void		insert_2(t_hashmap *hashmap, char *key, char *val);
char		*search(t_hashmap *hashmap, long long key);
void		free_hashmap(t_hashmap *hashmap);
void		print_ne_norm(char *str, t_hashmap *ne_norm, int l);
int			read_parse_dict(char *path, char **file_dict,
				t_hashmap *single, t_hashmap *hashmap);
char		*cut_str(char *str, int *len, int *l);
int			str_len_non_zero(char *s);

int	lookup_left(char *s, t_hashmap *singles, t_hashmap *hundred, int *flag)
{
	int	n;

	n = str_num(s);
	if (n / 100)
	{
		print_string_space(search(singles, n / 100), *flag);
		*flag = 1;
		print_string_space(search(hundred, 0), *flag);
		n = n % 100;
	}
	if (n / 10)
	{
		if (n >= 10 && n <= 19)
			return (print_string_space(search(singles, n), *flag));
		print_string_space(search(singles, (n / 10) * 10), *flag);
		n = n % 10;
		*flag = 1;
	}
	if (n)
	{
		print_string_space(search(singles, n), *flag);
	}
	*flag = 1;
	return (0);
}

int	check_zeros(char *str)
{
	int	i;

	i = 2;
	while (i >= 0)
	{
		if (str[i] != '0')
		{
			return (1);
		}
		i--;
	}
	return (0);
}

int	lookup(char *str, t_hashmap *ne_norm, t_hashmap *norm)
{
	int		len;
	int		l;
	char	*h;
	int		flag;

	while (*str == '0' && *str != '\0')
		str++;
	len = str_len(str);
	l = (len - 1) / 3;
	flag = 0;
	while (l)
	{
		if (search(ne_norm, l) == NULL)
			return (1);
		h = slice(str, 0, len - (l * 3) - 1);
		if (h != NULL)
			lookup_left(h, norm, ne_norm, &flag);
		free(h);
		print_ne_norm(str, ne_norm, l);
		str = cut_str(str, &len, &l);
	}
	lookup_left(str, norm, ne_norm, &flag);
	return (0);
}

int	validate_args(char **path, char **value, int argc, char **argv)
{
	if ((argc < 2) || (argc > 3))
	{
		print_string("Error\n");
		return (1);
	}
	if (argc == 3)
	{
		*path = argv[1];
		*value = argv[2];
	}
	else
	{
		*value = argv[1];
	}
	if (str_num(*value) == -1)
	{
		print_string("Error\n");
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	char		*value;
	char		*path;
	char		*file_dict;
	t_hashmap	*hashmap;
	t_hashmap	*single;

	value = NULL;
	path = "numbers.dict";
	hashmap = create_table();
	single = create_table();
	if (validate_args(&path, &value, argc, argv))
		return (1);
	if (read_parse_dict(path, &file_dict, single, hashmap))
		return (1);
	if (str_len_non_zero(value) == 0)
	{
		print_string(search(single, str_num(value)));
		return (0);
	}
	if (lookup(value, hashmap, single))
		print_string("Dict Error\n");
	free(file_dict);
	free_hashmap(hashmap);
	free_hashmap(single);
	return (0);
}
