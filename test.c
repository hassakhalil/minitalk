#include <stdio.h>

int	main()
{
	int		i = 61;
	while (++i < 256)
	{
		printf("index[%d] : [%c]\n", i,(unsigned char)i);
	}
	return 0;
}
