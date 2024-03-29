/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:26:01 by noam              #+#    #+#             */
/*   Updated: 2024/03/25 17:33:06 by noam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "libft/libft.h"
#include "get_next_line.h"
// #include "get_next_line_utils.c"`
#include <fcntl.h>
// #include "get_next_line_utils.c"

char	*read_write(char *str, int fd)
{
	static char		buff[BUFFER_SIZE + 1];
	int				red;

	red = 1;
	while (!ft_strchr(str, '\n') && red != 0)
	{
		red = read(fd, buff, BUFFER_SIZE);
		if (red < 0)
			return (NULL);
		buff[red] = '\0';
		str = ft_strjoin(str, buff);
	}
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE == 0 || read(fd, str, 0) < 0)
		return (NULL);
	str = read_write(str, fd);
	if (!str)
		return (NULL);
	line = get_line(str);
	str = restash(str);
	return (line);
}

/*
int	main(void)
{
	int	fd = open("example.txt", O_RDONLY);
	printf("RESULT %s|", get_next_line(fd));
	printf("RESULT %s|", get_next_line(fd));
	printf("RESULT %s|", get_next_line(fd));
	printf("RESULT %s|", get_next_line(fd));
	printf("RESULT %s|", get_next_line(fd));
	printf("RESULT %s|", get_next_line(fd));
	printf("RESULT %s|", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	close (fd);
}
*/
