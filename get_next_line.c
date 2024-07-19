/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkalkoul <nkalkoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 01:29:28 by nas91             #+#    #+#             */
/*   Updated: 2024/07/20 00:08:59 by nkalkoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

char	*before_line(char *line)
{
	size_t	i;
	char	*new;
	
	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\n')
		i++;
	new = malloc(sizeof(char) * (i + 1));
	if (new == NULL)
		return (free(line), NULL);
	ft_strlcpy(new, line, i + 1);
	return (free(line), new);
}

char	*after_line(char *save, char *line)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (line[i] && line[i] != '\n')
		i++;
	while (line[i])
		save[j++] = line[++i];
	return(save);
}

char	*get_next_line(int fd)
{
	int 		bf;
	char		*buffer;
	static char	save[BUFFER_SIZE + 1];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = ft_substr(save, 0, ft_strlen(save));
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer || !line)
		return (free(buffer), free(line), NULL);
	bf = 1;
	while (bf != 0 && !ft_strchr(line, '\n'))
	{
		bf = read(fd, buffer, BUFFER_SIZE);
		if (bf == -1)
			return (free(buffer), free(line), NULL);
		// if (bf == 0)
			// break;
		buffer[bf] = '\0';
		line = ft_re_strjoin(line, buffer);
	}
	free(buffer);
	after_line(save, line);
	line = before_line(line);
	if (*line == '\0')
		return (free(line), NULL);
	return (line);
}

// int	main(void)
// {
// 	int fd = open ("ey.txt", O_RDONLY);
// 	char	*str;

// 	str = get_next_line(fd);
// 	while (str)
// 	{
// 		printf("%s", str);
// 		free(str);
// 		str = get_next_line(fd);
// 	}

// 	return 0;
// }
