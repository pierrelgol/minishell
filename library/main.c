#include "include/clib.h"

int main(int argc, char **argv, char **envp)
{
	t_allocator *allocator;
	char       **split;
	char        *delimiter = "~!@#$%^&*()_+[]\\|\"\'<>,./?'";
	t_bitset     bitset;

	if (argc > 1)
	{
		bitset = bitset_init_from_str(delimiter);
		allocator = gpa_init();
		split = string_split_any(allocator, argv[1], &bitset);
		for (int i = 0; split[i]; i++)
		{
			printf("%s\n", split[i]);
		}
		allocator = gpa_deinit(allocator);
	}

	return (0);
}
