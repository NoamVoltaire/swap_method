#include "../utils/check_input.c"
#include "../utils/error.c"
#include "../utils/node_utils/node_utils.c"
#include "../utils/str_utils/ft_atol.c"
#include "../utils/str_utils/is_digit.c"
#include "../utils/str_utils/ft_strncmp.c"


int main (void)
{
	char	*good[] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", NULL};
	check_input(good);
	// char	*bad[] = {"1", "--2", "3", NULL};
	// check_input(bad);
	// char	*bad2[] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "2147483648", NULL};
	// check_input(bad2);
	// char	*bad3[] = {"  3 ", "2", "3"};
	// check_input(bad3);
	// char	*bad4[] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "1", NULL};
	// check_input(bad4);

	return (0);
}