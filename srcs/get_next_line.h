/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaoub <amsaoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 09:44:40 by mel-karm          #+#    #+#             */
/*   Updated: 2023/10/14 11:08:00 by amsaoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);

char	*ft_substr(char *str, size_t start, size_t len);

char	*ft_strjoin(char *s1, char *s2);

size_t	ft_strlen(char *str);

char	*ft_substr_s(char *str, size_t start, size_t len);

char	*ft_strchr(char *str, int c);
#endif