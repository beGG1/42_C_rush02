/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshabali <sshabali@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 11:27:47 by sshabali          #+#    #+#             */
/*   Updated: 2024/09/14 11:30:52 by sshabali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "custom_hashmap.h"

int		check_zeros(char *str);
char	*search(t_hashmap *hashmap, long long key);
/*
Function is doing:
prints a string provided as a parameter.
returns 1 - always
*/

int	print_string(char *msg)
{
	while (*msg)
	{
		write(1, msg, 1);
		msg++;
	}
	return (1);
}

int	print_string_space(char *msg, int flag)
{
	if (flag)
		write(1, " ", 1);
	while (*msg)
	{
		write(1, msg, 1);
		msg++;
	}
	return (1);
}

void	print_ne_norm(char *str, t_hashmap *ne_norm, int l)
{
	char	*out;

	out = NULL;
	if (check_zeros(str))
		out = search(ne_norm, l);
	if (out != NULL)
		print_string_space(out, 1);
}
