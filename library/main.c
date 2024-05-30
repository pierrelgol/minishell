#include "include/clib.h"

int main(int argc, char **argv)
{
	t_allocator *allocator;
	t_bitset bitset = bitset_init_from_str(" &|<>=()");
	char **split;

	if (argc == 2)
	{
		allocator = gpa_init();
		split = string_split_any(allocator, argv[1], &bitset);
		for (int i = 0; split[i]; i++)
			print(1, "%s\n", split[i]);
		allocator = gpa_deinit(allocator);
		
	}
}
