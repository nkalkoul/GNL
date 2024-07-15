/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nas91 <kalkoul.nassim@gmail.com>           #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-07-02 18:44:35 by nas91             #+#    #+#             */
/*   Updated: 2024-07-02 18:44:35 by nas91            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 12
#endif

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

size_t  ft_strlen(const char *s);
char    *ft_strchr(const char *s, char c);
char    *ft_strdup(const char *s);
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *s, size_t start, size_t len);
