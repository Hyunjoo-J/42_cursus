#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*s;

	fd = 0;
	while ((s = get_next_line(fd)))
		printf("%s", s);
}