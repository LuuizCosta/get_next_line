/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufernan <lufernan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 13:32:30 by lufernan          #+#    #+#             */
/*   Updated: 2021/07/07 19:11:47 by lufernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*rewrite(char *buffer, char *write_over)
{
	char	*temp;
	size_t	index;

	temp = buffer;
	index = 0;
	while (write_over[index] != '\0')
	{
		buffer[index] = write_over[index];
		index++;
	}
	buffer[index] = '\0';
	return (temp);
}

static char	*join(char *new_line, char *buffer)
{
	char	*new_string;
	size_t	full_size;

	full_size = (ft_strlen(new_line) + ft_strlen(buffer) + 1);
	new_string = malloc(full_size * sizeof(char));
	if (!new_string)
	{
		free (new_line);
		return (NULL);
	}
	new_string = ft_strcpycat(new_string, new_line, buffer);
	free(new_line);
	return (new_string);
}

static char	*keep_reading(int fd, char *nl, char *b, int *ifnl)
{
	char		*found_newline;
	long int	bytes;

	while (*ifnl == 0)
	{
		bytes = check_bytes(fd, &b, &nl);
		if (bytes < 0)
			return (NULL);
		b[bytes] = '\0';
		nl = join(nl, b);
		if (!nl)
			return (NULL);
		found_newline = ft_strchr(nl);
		if (found_newline != NULL)
		{
			*ifnl = 1;
			*found_newline = '\0';
			found_newline = ft_strchr(b);
			rewrite(b, found_newline + 1);
		}
		if (bytes == 0)
			break ;
	}
	return (nl);
}

static char	*first_read(char *buffer, int *if_newline)
{
	char	*new_line;
	char	*found_newline;

	if (buffer[0] == '\0')
		return (ft_strdup(""));
	new_line = ft_strdup(buffer);
	found_newline = ft_strchr(buffer);
	if (found_newline == NULL)
		return (new_line);
	*if_newline = 1;
	new_line = join(new_line, buffer);
	if (!new_line)
		return (NULL);
	found_newline = ft_strchr(new_line);
	*found_newline = '\0';
	found_newline = ft_strchr(buffer);
	rewrite(buffer, found_newline + 1);
	return (new_line);
}

int	get_next_line(int fd, char **line)
{
	static char	buffer[RLIMIT_NOFILE][BUFFER_SIZE + 1];					//The only change from the normal GNL. Buffer is now a 2d array, that can get multiple fds.
	char		*new_line;
	int			if_newline;

	if_newline = 0;
	if (fd < 0 || fd > RLIMIT_NOFILE || !(line) || BUFFER_SIZE <= 0)
		return (-1);
	new_line = first_read(buffer[fd], &if_newline);
	if (!new_line)
		return (-1);
	new_line = keep_reading(fd, new_line, buffer[fd], &if_newline);
	*line = new_line;
	if (!new_line)
		return (-1);
	if (if_newline == 0)
		return (0);
	return (1);
}
