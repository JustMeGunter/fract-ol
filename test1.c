#include <limits.h>
#include <stdio.h>

int	main()
{
	unsigned long x = 0;
	while (x < ULONG_MAX)
	{
		if (x % 1000000 == 0)
			printf("%lu", x);
		x++;
	}
}
