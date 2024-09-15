/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshabali <sshabali@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 07:34:17 by sshabali          #+#    #+#             */
/*   Updated: 2024/09/15 07:34:26 by sshabali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "custom_hashmap.h"
#include <stdlib.h>

// declarations from another files:
int		print_string(char *msg);
void	parse_dict(char *dict, int size,
			t_hashmap *single, t_hashmap *hashmap);
/*
Function accepts as a parameters:
 - path to a file

 It opens file, reads content byte by byte, closes file.
 Returns size of a file or zero.
*/

int	get_file_size(char *path)
{
	int		size;
	int		fd;
	char	buf;

	fd = open(path, O_RDONLY | O_NONBLOCK);
	if (fd == -1)
	{
		print_string("Dict Error\n");
		return (0);
	}
	size = 0;
	while ((read(fd, &buf, 1)) == 1)
	{
		size++;
	}
	if (close(fd) < 0) 
	{
		print_string("Dict Error\n");
		return (0);
	}
	return (size);
}

/*
 Function accepts as a parameters:
 - path to a file
 - size of a file
 - pointer to a buffer where contect of a file would be located.
    
    Memory should be allocated in advance.

 opens a file, read whole content in a buffer of "size" and closes a file.
 Function returns a pointer to a buffer of type char*.
 In this buffer, there are 
*/
char	*read_full_file(char *path, int size, char *buffer)
{
	int	fd;

	fd = open(path, O_RDONLY | O_NONBLOCK);
	if (fd == -1)
	{
		print_string("Dict Error\n");
		return (NULL);
	}
	if (read(fd, buffer, size) == -1) 
	{
		print_string("Dict Error\n");
		return (NULL);
	}
	if (close(fd) < 0) 
	{
		print_string("Dict Error\n");
		return (NULL);
	}
	return (buffer);
}

int	read_parse_dict(char *path, char **file_dict,
	t_hashmap *single, t_hashmap *hashmap)
{
	int	file_size;

	file_size = get_file_size(path);
	if (file_size == 0)
		return (1);
	*file_dict = malloc(file_size);
	if (*file_dict == NULL)
	{
		print_string("Dict Error\n");
		return (1);
	}
	*file_dict = read_full_file(path, file_size, *file_dict);
	if (*file_dict == NULL)
		return (1);
	parse_dict(*file_dict, file_size, single, hashmap);
	return (0);
}
