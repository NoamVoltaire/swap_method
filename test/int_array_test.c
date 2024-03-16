#include "../int_array_sorted.c"
#include "../utils/str_utils/ft_atol.c"
#include <stdio.h>


int main (void)
{
/* ************************************************************************** */

	char	*good[] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", NULL};
	int		*array = strings_to_int_array(good, 10);

	int		i = 0;
	
	while (array[i])
	{
		printf("%d\n", array[i]);
		i++;
	}

/* ************************************************************************** */

	i = 0;

	char	*good2[] = {"1", NULL};
	int		*array2 = strings_to_int_array(good2, 1);

		while (array2[i])
	{
		printf("%d\n", array2[i]);
		i++;
	}

/* ************************************************************************** */

		i = 0;

	char	*good3[] = {"-2147483648", NULL};
	int		*array3 = strings_to_int_array(good3, 1);

		while (array3[i])
	{
		printf("%d\n", array3[i]);
		i++;
	}

/* ************************************************************************** */

		i = 0;

	char	*bad[] = {"", NULL};
	int		*array4 = strings_to_int_array(bad, 0);

		while (array4[i])
	{
		printf("%d\n", array4[i]);
		i++;
	}

/* ************************************************************************** */
	return (0);


}