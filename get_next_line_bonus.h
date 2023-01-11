/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraffi-k <rraffi-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 11:49:58 by rraffi-k          #+#    #+#             */
/*   Updated: 2023/01/06 12:28:39 by rraffi-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <fcntl.h>

size_t	ft_strlen(const char *s);
int		ft_strnchr(const char *s);
char	*ft_strdup(const char *s);
void	ft_new_buffer(char *str);
char	*ft_strjoin_n(char *s1, char *s2);
void	ft_empty_buffer(char *buffer);
char	*get_next_line(int fd);

#endif
