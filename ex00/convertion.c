/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshabali <sshabali@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 11:32:45 by sshabali          #+#    #+#             */
/*   Updated: 2024/09/14 11:45:20 by sshabali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/*
Function takes a pointer to string as a parameter 
and converts it into a long long integer.
it skips spaces at the beggining of a string and 
only processes the valid digits. 
Procesing stops when non-digit character accurs.
Details:

1/ Result of conversion.

2/ The loop iterates until the end of the string so each character
of the string is processed one at a time.

3/ If the character is a digit the function converts it to 
its numerical value by substracting the ASCII value of '0'.
the current value of num then is updated by multiplying it 
by 10 and adding the current digit.
this handles the positional value of the digits.

4/ the function sets the "num" to -1 if the character is not 
a digit or a space.
*/
long long	str_num(char *str)
{
	long long	num;

	if (str == NULL)
		return (-1);
	num = 0;
	while (*str)
	{
		if (*str == ' ')
		{
			str++;
			continue ;
		}
		if (*str >= '0' && *str <= '9')
			num = num * 10 + (*str - '0');
		else
		{
			num = -1;
			break ;
		}
		str++;
	}
	return (num);
}

char	*slice(char *s, int from, int to)
{
	char	*o;
	int		i;

	i = 0;
	o = malloc(sizeof(char) * (to - from + 2));
	while (from < to)
	{
		o[i] = s[from];
		i++;
		from++;
	}
	o[i] = s[from];
	o[i + 1] = '\0';
	return (o);
}

int	str_len(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	str_len_non_zero(char *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != '0')
			count++;
		i++;
	}
	return (count);
}

char	*cut_str(char *str, int *len, int *l)
{
	if (*len == *l * 3)
		str += 3;
	else
		str = str + (*len - (*l * 3));
	*len = str_len(str);
	*l = (*len - 1) / 3;
	return (str);
}
