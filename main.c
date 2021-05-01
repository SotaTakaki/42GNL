
#include "get_next_line.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int	main(void)
{
	char	*line = NULL;
	int		i;
	int		fd;

	fd = open("takaki.txt", 0);
	i = get_next_line(fd, &line);
	printf("%d:%s\n", i, line);
//	free(line);

	i = get_next_line(fd, &line);
	printf("%d:%s\n", i, line);
//	free(line);

	i = get_next_line(fd, &line);
	printf("%d:%s\n", i, line);
//	free(line);

	i = get_next_line(fd, &line);
	printf("%d:%s\n", i, line);
//	free(line);

	i = get_next_line(fd, &line);
	printf("%d:%s\n", i, line);
//	free(line);

	i = get_next_line(fd, &line);
	printf("%d:%s\n", i, line);
//	free(line);

	i = get_next_line(fd, &line);
	printf("%d:%s\n", i, line);
//	free(line);

	i = get_next_line(fd, &line);
	printf("%d:%s\n", i, line);

	i = get_next_line(fd, &line);
	printf("%d:%s\n", i, line);
	close(fd);
}
