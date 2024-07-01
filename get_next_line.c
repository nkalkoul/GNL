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

#include  <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_buffsiz(int fd)
{
	size_t 	bf;
	char	*buffer;
	int		count;
	char temp;

	temp = 0;
	count = 0;
	bf = -1;
	buffer = &temp;
	while (*buffer != '\n')
	{
		bf = read(STDIN_FILENO, buffer, 1);
		printf("buff = %s%%\n", buffer);
		count++;
		if (bf == 0)
		{
			return (count);
		}
	
	}
	printf("bf = %zu\n", bf);
	return (count);
}

int	main(void)
{
	int i = 0;
	while (i < 3)
	{
		printf("count = %d\n", ft_buffsiz(STDIN_FILENO));
		i++;
	}
	return 0;
}
char	*get_next_line(int fd)
{
	static
}