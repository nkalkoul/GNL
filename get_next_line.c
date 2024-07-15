/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nas91 <kalkoul.nassim@gmail.com>           #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-07-01 01:29:28 by nas91             #+#    #+#             */
/*   Updated: 2024-07-01 01:29:28 by nas91            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	buffsize(char *temp, int count)
{
	int	i;

	i = 0;
	while (temp[count] && temp[count] != '\n')
		{
			count++;
			i++;
		}
	return (i);
}

char	*ft_stopline(char *temp)
{
	char		*line;
	static int	count = 0;


	line = ft_substr(temp, count, buffsize(temp, count) + 1);
	while (temp[count] && temp[count] != '\n')
		count++;
	if (!temp[count - 1])
		{
			free(temp);
			return (NULL);
		}
	count++;
	return (line);
}

char	*get_next_line(int fd)
{
	int 		bf;
	char		*buffer;
	static char	*temp;
	char		*line;

	if (fd < 0 || fd > 1024)
		return (NULL);
	buffer = malloc(sizeof(char) * BUFFER_SIZE);
	if (!buffer)
		return (NULL);
	bf = 1;
	while (bf != 0 || !ft_strchr(temp, '\n'))
	{
		bf = read(fd, buffer, BUFFER_SIZE);
		if (bf == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bf] = '\0';
		temp = ft_strjoin(temp, buffer);
	}
	line = ft_stopline(temp);
	if (line == NULL)
	{
		free(line);
		return (NULL);
	}
	free(buffer);
return (line);
}

int	main(void)
{
	printf("//line =.%s%%", get_next_line(STDIN_FILENO));
	printf("//line =.%s%%", get_next_line(STDIN_FILENO));
	printf("//line =.%s%%", get_next_line(STDIN_FILENO));
	printf("//line =.%s%%", get_next_line(STDIN_FILENO));

	return 0;
}
