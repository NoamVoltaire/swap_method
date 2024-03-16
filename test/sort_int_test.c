#include "../int_array_sorted.c"
#include "../utils/str_utils/ft_atol.c"
#include <stdio.h>


int main (void)
{
/* ************************************************************************** */

	char	*good[] = {"9", "2", "4", "3", "5", "6", "7", "8", "1", "10", NULL};
	int		*array = int_array_sorted(good, 10);
	int		i = 0;
	
	while (array[i])
	{
		printf("%d\n", array[i]);
		i++;
	}

	printf("\n");
}