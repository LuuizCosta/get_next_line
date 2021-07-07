/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufernan <lufernan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 21:53:36 by lufernan          #+#    #+#             */
/*   Updated: 2021/06/23 17:38:05 by lufernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <sys/resource.h>

int		get_next_line(int fd, char **line);

char	*ft_strchr(char *string);
size_t	ft_strlen(char *s);
char	*ft_strdup(char *string);
char	*ft_strcpycat(char *dest, char *first, char *second);
int		check_bytes (int fd, char **b, char **nl);
#endif