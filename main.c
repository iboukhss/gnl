#include "get_next_line.h"

#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int fd = open("romeo-full.txt", O_RDONLY);

	while (true)
	{
		char *line = get_next_line(fd);
		if (!line)
			break ;
		printf("%s", line);
		free(line);
	}
	return (0);
}
