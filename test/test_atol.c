#include "../utils/str_utils/ft_atol.c"
#include <stdio.h>

int main (void)
{
	printf("%d ", ft_atol("123") == 123);
	printf("%d ", ft_atol("-123") == -123);
	printf("%d ", ft_atol("0") == 0);
	printf("%d ", ft_atol("2139102483741890") == 2139102483741890);
}
