/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkalkoul <nkalkoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 18:44:35 by nas91             #+#    #+#             */
/*   Updated: 2024/07/19 19:45:33 by nkalkoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

size_t  ft_strlen(const char *s);
char    *ft_strchr(const char *s, char c);
char    *ft_strdup(const char *s);
char	*get_next_line(int fd);
char	*ft_re_strjoin(char *s1, char *s2);
char	*ft_substr(char *s, size_t start, size_t len);
char	*ft_calloc(size_t size, size_t ncount);
size_t	ft_strlcpy(char *dest, char *src, size_t len_of_s1);
