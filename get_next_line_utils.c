/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nas91 <kalkoul.nassim@gmail.com>           #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-07-12 03:43:43 by nas91             #+#    #+#             */
/*   Updated: 2024-07-12 03:43:43 by nas91            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t  ft_strlen(const char *s)
{
    int     i;

    i = 0;
    while (s[i])
        i++;
    return (i);
}

char    *ft_strchr(const char *s, char c)
{
    size_t  i;

	i = 0;
    while (*(s + i))
    {
        if (*(s + i) == c)
			return ((char *)(s + i));
        i++;
    }
    if (c == 0 && *(s + i) == 0)
		return (((char *)s + i));
    return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new;
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		s1[0] = 0;
	}
	new = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!new || !s1)
		return (NULL);
	while (s1[++i])
		new[i] = s1[i];
	while (s2[j])
	{
		new[i + j] = s2[j];
		j++;
	}
	new[i + j] = 0;
	return (new);
}

char	*ft_substr(char  *s, size_t start, size_t len)
{
	char	*new;
	size_t	i;

	i = 0;
	if (start >= ft_strlen(s))
	{
		new = malloc(1);
		if (new == NULL)
			return (NULL);
		new[0] = '\0';
		return (new);
	}
	if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	new = malloc(sizeof(char) * len + 1);
	if (new == NULL)
		return (NULL);
	while (i < len)
	{
		new[i] = s[start + i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
