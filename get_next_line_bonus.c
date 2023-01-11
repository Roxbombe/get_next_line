/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraffi-k <rraffi-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 17:29:25 by rraffi-k          #+#    #+#             */
/*   Updated: 2023/01/10 10:57:47 by rraffi-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 4096
#endif

void	ft_new_buffer(char *str)
{
	size_t		i;
	size_t		j;

	i = 0;
	if (!ft_strnchr(str))
	{
		str[0] = '\0';
		return ;
	}
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i])
		i++;
	j = 0;
	while (str[i + j])
	{
		str[j] = str[i + j];
		j++;
	}
	str[j] = '\0';
}

char	*get_next_line(int fd)
{
	static char	buffer[1024][BUFFER_SIZE + 1];
	char		*str;
	ssize_t		bytes_read;

	bytes_read = 1;
	str = ft_strdup("\0");
	if (!str)
		return (NULL);
	while (bytes_read && !(ft_strnchr(str)))
	{
		if (!buffer[fd][0])
		{
			bytes_read = read(fd, buffer[fd], BUFFER_SIZE);
			if (bytes_read == -1)
				return (free(str), NULL);
			buffer[fd][bytes_read] = '\0';
		}
		str = ft_strjoin_n(str, buffer[fd]);
		if (!str)
			return (NULL);
		ft_new_buffer(buffer[fd]);
	}
	if (!bytes_read && !str[0])
		return (free(str), NULL);
	return (str);
}

// int main() 
// {
// 	int fd = open("file1.txt", 2);
// 	int fd2 = open("file2.txt", 2);
// 	printf("%s", get_next_line(fd2));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd2));
// 	// printf("%s", get_next_line(fd));
// 	// printf("%s", get_next_line(fd2));
// 	// printf("%s", get_next_line(fd));
// 	// printf("%s", get_next_line(fd));
// 	// printf("%s", get_next_line(fd));

// 	// char	*s;
// 	// while ((s = get_next_line(fd)))
// 	// {
// 	//  	printf("%s\n", s);
// 	//  	free(s);
// 	// }
// 	return (0);
// }
