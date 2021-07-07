/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufernan <lufernan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 16:34:47 by lufernan          #+#    #+#             */
/*   Updated: 2021/06/23 17:37:53 by lufernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strdup(char *string)
{
	size_t	lenght;
	size_t	index;
	char	*new_string;

	lenght = ft_strlen (string) + 1;
	index = 0;
	new_string = malloc(lenght * sizeof(char));
	if (!new_string || !string)
		return (NULL);
	while (string[index] != '\0')
	{
		new_string[index] = string[index];
		index++;
	}
	new_string[index] = '\0';
	return (new_string);
}

size_t	ft_strlen(char *s)
{
	size_t	lenght;

	lenght = 0;
	while (s[lenght] != '\0')
		lenght++;
	return (lenght);
}

char	*ft_strchr(char *string)
{
	size_t	index;

	index = 0;
	while (string[index] != '\0')
	{
		if (string[index] == '\n')
			return ((char *)string + index);
		index++;
	}
	return (NULL);
}

char	*ft_strcpycat(char *dest, char *first, char *second)
{
	size_t	first_size;
	size_t	second_size;

	first_size = 0;
	second_size = 0;
	while (first[first_size] != '\0')
	{
		dest[first_size] = first[first_size];
		first_size++;
	}
	while (second[second_size] != '\0')
	{
		dest[first_size + second_size] = second[second_size];
		second_size++;
	}
	dest[first_size + second_size] = '\0';
	return (dest);
}

int	check_bytes(int fd, char **b, char **nl)
{
	long int	bytes;

	bytes = read (fd, *b, BUFFER_SIZE);
	if (bytes < 0)
	{
		free(*nl);
		return (-1);
	}
	return (bytes);
}
